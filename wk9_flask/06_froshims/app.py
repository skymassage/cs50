from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRANTS = {} # If you press ctrl+C to exit, the registration form will be cleared.
SPORTS = ["Basketball", "Soccor", "Ultimate Frisbee"]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    # If "name" is blank, i.e., you don't type anything and just submit it out.
    # Note that the hackers can cancel the attribute "required" in the <input> tag of the index.html from their browser's developer tools,
    # so they can type nothing and just submit blank out to break the original setup of your page.
    # So we should check if "name" is blank.
    if not name:
        return render_template("failure.html")

    sport = request.form.get("sport")
    # If the hackers change the "value" attribute of <option> and submit this option.
    # For example, they can change a sport to "volleyball" from their browser and submit it to our server.
    # This cause the "registrant" page showing the "volleyball" different from "SPORTS" we previously set.
    # So we should check if "sport" is in "SPORTS".
    if sport not in SPORTS:
        return render_template("failure.html")

    REGISTRANTS[name] = sport # Note that the dict appends a new key-value pair like this.

    return render_template("success.html")

# Add "/registrants" after the base URL to see the submitted data.
@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS) # You can't have a function that's the same name as a variable, so that's why the dictionary "registrants" is capitalized.
