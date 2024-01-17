from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

app = Flask(__name__)

db = SQL("sqlite:///history.db")

# If True, reload the templates when they are changed, but not when the application is in debugging mode
# (provided we're in debugging mode, which we are by default in the code50 codespace)
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        if request.form.get("delete"):
            db.execute("DELETE FROM history;")
            return render_template("index.html", random_string="Search history has been deleted!")

        try:
            page = int(request.form.get("page")) # Whenever you use request.form.get or request.args.get, you'll always get your input back as a string.
        except ValueError:
            return render_template("index.html", random_string="Enter a number!")

        if page <= 0:
            return render_template("index.html", random_string="Type in a positive number!")

        db.execute("INSERT INTO history (page) VALUES (?);", page)
        random.seed(page) # I ask for the same page again and again, I'll get the same random string every time.

    string = random_string(1000)
    rows = db.execute("SELECT * FROM history;")
    return render_template("index.html", random_string=string, history=rows)
