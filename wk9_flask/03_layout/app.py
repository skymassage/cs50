from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet")
def greet():
    return render_template("greet.html", placeholder=request.args.get("your_name", "world"))
