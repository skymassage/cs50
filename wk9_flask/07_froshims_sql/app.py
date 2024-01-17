# Implements a registration form, storing registrants in a SQLite database, with support for deregistration.
from flask import Flask, redirect, render_template, request
from cs50 import SQL
# Note that we use another third library "CS50", so add it to "requirement.txt"

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # The registration form will be stored in the database.
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    return redirect("/registrants")
    # "redirect" is to redirect the current URL to another URL, "render_template" uses the template to render the requested URL.


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)


@app.route("/deregister", methods=["POST"])
def deregister():

    # Clear registrant
    id = request.form.get("id")
    if id:   # If there's indeed an ID, that is it's not blank.
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")
