from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

# Inform Flask that the method is "POST" (not the default "GET"), the value of which is a list. Submit it to the "/greet" route.
# This tells the server to look deeper in the virtual envelope in POST and not reveal the items in the URL.
# Note that you will get HTTP 404 if you add "/greet" to the home URL.
@app.route("/greet", methods=["POST"])
def greet():
    return render_template("greet.html", placeholder=request.form.get("your_name", "world"))
    # Note that we use "request.form.get" rather than "request.args.get". "request.args" is only used for GET.
    # When using GET, "request.args" is a dictionary that contains all of your key value pairs.
    # When using POST with Flask, you have to go into "request.form".
