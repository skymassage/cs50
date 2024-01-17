from flask import Flask, render_template, request

app = Flask(__name__)

# We can be advanced further by utilizing a single route for both GET and POST.
# Note that both GET and POST are done in a single routing.
# However, "request.method" is utilized to properly route based upon the type of routing requested by the user.
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # When I submit the form, I won't go to ".../greet" and I will be still at home page (index.html and greet.html are just templates).
        return render_template("greet.html", placeholder=request.form.get("your_name", "world"))
    return render_template("index.html")
