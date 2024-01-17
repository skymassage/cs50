from flask import Flask, render_template, request

app = Flask(__name__)

# If index.html's purpose is just to spit out this form, we're done with one of my routes.
@app.route("/")
def index():
    return render_template("index.html")

# The second route "/greet" that actually spits out some greeting to the user.
@app.route("/greet")
def greet():
    return render_template("greet.html", placeholder=request.args.get("your_name", "world")) # Note that the key is "your_name" which is used to reference the submitted form data.
