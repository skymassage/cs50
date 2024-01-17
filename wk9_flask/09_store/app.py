from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANENT"] = False   # Note that closing the browser will clear the cart.
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():

    # Ensure that there is at least an empty cart the first time the user add the book to cart.
    if "cart" not in session:
        session["cart"] = [] # The value of the key "cart" is an empty list.

    # POST
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")

    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    # session["cart"] is a list which look like [id_1, id_2, ...], but to SQL it looks like "id_1", "id_2", ....
    # And you need to put them into (), i.e.,  ("id_1", "id_2", ...), to comply with SQL syntax. That's why here is "(?)".
    # Note that "books" is a list where each element is a dict and has the keys "id" and "title".

    # Even if you don't add books to the shopping cart in order,
    # the SQL command will list the books in the order of "id" in store.db.
    # And if you add the same book repeatedly (i.e. more than one same "id" in the list session["cart"]),
    # it won't select the same book repeatedly.

    return render_template("cart.html", books=books)
