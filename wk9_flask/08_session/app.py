# In the previous example (7_froshims), there is a risk that not only the administrator,
# but any user can hit the deregister button to deregister other registrants.
# We can actually address this issue using cookies or sessions.

# A cookie is a small text file that is saved on the user's computer and its maximum file size is 4KB.
# When a user first visits a website, the site sends data packets to the user's computer in the form of a cookie.
# Cookies are used to track the user's activities on the web and reflect some suggestions according to the user's choices to enhance the user's experience.
# The information stored in cookies is not safe since it is kept on the client-side in a text format that anybody can see.

# The concept of a session is very much similar to that of a cookie.
# A session is used to save information on the server momentarily so that it may be utilized across various pages of the website.
# It is the overall amount of time spent on an activity.
# The user session begins when the user logs in to a specific network application, and ends when the user logs out of the program or shuts down the machine.
# Session values are far more secure since they are saved in binary or encrypted form and can only be decoded at the server.
# When the user shuts down the machine or logs out of the program, the session values are automatically deleted, so we must save the values in the database to keep them forever.

from flask import Flask, redirect, render_template, request, session # Here the imported "session" is a dictionary-like object that allows you to store and retrieve data in the session.
from flask_session import Session # Note that we use another third library "flask_session", so we also include "Flask-Session" in the requirement.txt.

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
# If False, it means that if the browser is closed, the "session" will be cleared.
# If True, it means that even if the browser is closed during the permanent_session_lifetime (default is 31 days), the "session" is still valid.

app.config["SESSION_TYPE"] = "filesystem"
# It tells Flask to store session data in the server's hard drive ("flask_session" folder)
# or any online ide account, and it is an alternative to using a Database or something else like that.

Session(app)
# Enabled sessions in your Flask app, you can access the session data using the "session" object provided by Flask.


@app.route("/")
def index():
    # To retrieve data from "session", you can use ".get()" of it.
    # This method takes the key of the value you want to retrieve as its argument,
    # and returns the value if it exists, or None if it does not exist.
    if not session.get("name_placeholder"):
        return redirect("/login")
    return render_template("index.html") # You can treat index.html as the home page, but if you are not logged in you will be redirected to the login page.


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name_placeholder"] = request.form.get("name_form")  # To store data in "session", you can use assign values to its keys as a dict
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session["name_placeholder"] = None
    return redirect("/")
