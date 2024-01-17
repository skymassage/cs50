# Searches for shows using Ajax with JSON
from cs50 import SQL
from flask import Flask, jsonify, render_template, request
# "jsonify" in Flask is used to convert Python data structures like dictionaries and lists into a JSON format,
# which can then be returned as a response from a Flask route.
# This is particularly useful when building APIs, as JSON is a common format for sending and receiving data.

# JSON (JavaScript Object Notation) is a lightweight data-interchange format,
# and a JSON file is a text file with the extension .json.
# The JSON format is a text-based data format following JavaScript object syntax,
# which was designed to be human-readable and easy for machines to parse and generate.
# Despite its relation to JavaScript, it is language-independent,
# with many programming languages including methods to read and generate JSON data.

# JSON format can represent a variety of data structures. Here are a few more examples:
# 1. A single value: "Hello, CS50!"
# 2. An array of values: [1, 2, 3, 4, 5]
# 3. A more complex object: {"course": "CS50", "topics": ["C", "Python", "SQL"], "details": {"year": 2022, "instructor": "David J. Malan"}}
# The last example shows how JSON can represent nested data structures.
# And JSON keys are always strings, and the values can be various types,
# including strings, numbers, objects (JSON objects), arrays, booleans, or null.

app = Flask(__name__)
db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


# Here, when you append "/search?q=..." to the root URL and go to this route, you will see the search results displayed in the JSON format.
@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return jsonify(shows) # The JSON format here is a list of dictionaries.
