# The reading order is from the function login -> logout -> register -> quote -> buy -> index -> history -> sell.
import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd, qualify
import datetime
import pytz

app = Flask(__name__)

app.jinja_env.filters["usd"] = usd # Custom filter
# In Jinja2, a templating engine used in Flask, filters are used to modify variables within templates before they are rendered
# and sent to the client. In this case, the "usd" filter is a custom filter that's being added to the Jinja2 environment.
# This filter would be a function (here is the function usd already defined elsewhere in our code) that takes a number
# and formats it as a US dollar amount. Once this filter is added, it can be used in any Jinja2 template in the application.
# For example, if you have a variable called price in your html template, you can display it as US dollars with {{ price | usd }}.

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# You need to "CREAT TABLE" into this database to finish implementing all of the features of the web application.
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required  # "@login_required" ensures that, if a user tries to visit any of those routes, they will first be redirected to "/login".
def index():
    user_id = session.get("user_id")
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    user_holding = db.execute("SELECT symbol, shares FROM holding WHERE user_id = ? ORDER BY symbol", user_id)

    portfolio, total_value = [], 0
    for row in user_holding:
        symbol, shares = row["symbol"], row["shares"]
        price = lookup(symbol)["price"]
        total_price = float(price) * int(shares)
        total_value += total_price

        stock = {}
        stock["symbol"], stock["price"], stock["shares"], stock["total"] = symbol, price, shares, total_price
        portfolio.append(stock)

    return render_template("index.html", portfolio=portfolio, cash=cash, total_value=total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol, shares = request.form.get("symbol"), request.form.get("shares")
        if not symbol or not shares:
            return apology("missing ticker symbol or number of shares", 400)

        stock, trade_date = lookup(symbol), datetime.datetime.now(pytz.timezone("US/Eastern"))
        if stock is None:
            return apology(f"{symbol} does not exist", 400)

        try:
            shares = int(shares)
            if shares <= 0:
                return apology("the number of shares should be positive", 400)
        except:
            return apology("enter a positive number for the number of shares", 400)

        total_price, symbol = float(stock["price"]) * shares, stock["symbol"]

        user_id = session.get("user_id")
        user = db.execute("SELECT * FROM users WHERE id = ?", user_id)[0]
        new_cash = float(user["cash"]) - total_price
        if new_cash < 0:
            return apology("can't afford", 400)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        holding_symbol = db.execute("SELECT * FROM holding WHERE user_id = ? AND symbol = ?", user_id, symbol)
        if not holding_symbol:
            db.execute("INSERT INTO holding(user_id, symbol, shares, total) VALUES(?, ?, ?, ?)", user_id, symbol, shares, total_price)
        else:
            new_shares = int(holding_symbol[0]["shares"]) + shares
            new_total = float(holding_symbol[0]["total"]) + total_price
            db.execute("UPDATE holding SET shares = ?, total = ? WHERE user_id = ? AND symbol = ?", new_shares, new_total, user_id, symbol)

        db.execute("INSERT INTO history(user_id, symbol, shares, total, action, date) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, shares, total_price, "BOUGHT", trade_date)

        flash("Bought!")
        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    user_records = db.execute("SELECT * FROM history WHERE user_id = ?", session.get("user_id"))
    return render_template("history.html", history=user_records)


@app.route("/login", methods=["GET", "POST"])
def login():
    session.clear()  # Forget any user_id

    if request.method == "POST":  # User reached route via POST (as by submitting a form via POST)

        if not request.form.get("username"):   # Ensure username was submitted
            return apology("must provide username", 403)


        elif not request.form.get("password"):          # Ensure password was submitted
            return apology("must provide password", 403)

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))  # Query database for username

        # Ensure username exists and check password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")): # "check_password_hash" compares the hash of the user's password with the hash of the password the user entered.
            return apology("invalid username and/or password", 403)

        session["user_id"] = rows[0]["id"]  # Remember which user has logged in

        flash("You have successfully logged in!")
        return redirect("/")  # Redirect user to home page

    else:                                       # User reached route via GET (as by clicking a link or via redirect)
        return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()  # Forget any user_id
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("enter symbol", 400)

        stock = lookup(symbol)
        # "None" is a singleton in Python, which means there is only ever one instance of "None".
        # Thus, using "is" (which checks if both variables are the same object, not just equivalent)
        # is more appropriate more efficient when checking for "None".
        if stock is None:
            return apology(f"{symbol} does not exist", 400)

        return render_template("quoted.html", name=stock["name"], symbol=stock["symbol"], price=stock["price"])

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username, password, confirmation = request.form.get("username"), request.form.get("password"), request.form.get("confirmation")
        user = db.execute("SELECT * FROM users WHERE username = ?", username)
        if not username:                                # Check if username is empty. Or you can use: if username == ""
            return apology("enter your username", 400)
        elif user and username == user[0]["username"]:
            return apology("this username has already been taken", 400)

        if not password or not confirmation:
            return apology("enter your password and confirm it", 400)
        elif password != confirmation:
            return apology("passwords don't match", 400)

        qualification = qualify(password)
        if qualification == 1:
            return apology("password length must be between 7 and 15 characters", 400)
        elif qualification == 2:
            return apology("password cannot contain anything other than digits and letters", 400)
        elif qualification == 3:
            return apology("password must contain digits, uppercase and lowercase letters", 400)

        db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", username, generate_password_hash(password))

        flash("Registered Successful!")
        return redirect("/")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    user_id = session.get("user_id")
    holding_symbols = db.execute("SELECT symbol, shares FROM holding WHERE user_id = ? ORDER BY symbol", user_id)
    symbols = []
    for holding_symbol in holding_symbols:
        symbols.append(holding_symbol["symbol"])

    if request.method == "POST":
        symbol, shares = request.form.get("symbol"), request.form.get("shares")
        if not symbol or not shares:
            return apology("missing ticker symbol or number of shares", 400)

        if symbol not in symbols:
            return apology(f"you do not have any shares of {symbol}", 400)

        try:
            shares = int(shares)
            if shares <= 0:
                return apology("the number of shares should be positive", 400)
        except:
            return apology("enter a positive number for the number of shares", 400)

        for holding_symbol in holding_symbols:
            if holding_symbol["symbol"] == symbol:
                if int(holding_symbol["shares"]) >= shares:
                    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
                    earning, trade_date = lookup(symbol)["price"] * shares, datetime.datetime.now(pytz.timezone("US/Eastern"))
                    new_cash = float(cash) + float(earning)
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

                    old_shares = int(holding_symbol["shares"])
                    new_shares = old_shares - shares
                    if new_shares == 0:
                        db.execute("DELETE FROM holding WHERE user_id = ? AND symbol = ?", user_id, symbol)
                    else:
                        db.execute("UPDATE holding SET shares = ? WHERE user_id = ? AND symbol = ?", new_shares, user_id, symbol)

                    db.execute("INSERT INTO history(user_id, symbol, shares, total, action, date) VALUES(?, ?, ?, ?, ?, ?)", user_id, symbol, shares, earning, "SOLD", trade_date)

                else:
                    return apology("you do not have the selected amount of shares", 400)

        flash("Sold!")
        return redirect("/")

    return render_template("sell.html", symbols=symbols)

@app.route("/password", methods=["GET", "POST"])
@login_required
def password():
    if request.method == "POST":
        old, new, confirmation = request.form.get("old"), request.form.get("new"), request.form.get("confirmation")
        user_id = session.get("user_id")
        user = db.execute("SELECT * FROM users WHERE id = ?", user_id)[0]

        if not old or not new or not confirmation:
            return apology("all fields should not be blank", 400)

        if not check_password_hash(user["hash"], old):
            return apology("old password is wrong", 400)

        if new != confirmation:
            return apology("new passwords don't match", 400)

        qualification = qualify(new)
        if qualification == 1:
            return apology("password length must be between 7 and 15 characters", 400)
        elif qualification == 2:
            return apology("password cannot contain anything other than digits and letters", 400)
        elif qualification == 3:
            return apology("password must contain digits, uppercase and lowercase letters", 400)

        hashed = generate_password_hash(new)
        db.execute("UPDATE users SET hash = ? WHERE id = ?", hashed, user_id)

        flash("Password Reset Completed!")
        return redirect("/")

    return render_template("password.html")
