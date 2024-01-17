from flask import Flask, render_template, request
# "requirements.txt" in the current folder is just a text file that allows you to enumerate all of the third party libraries your application might want to use.
# It's a convention so that the server can automatically install things for you without you having to do it manually.
# Now we just use "Flask", so just type it in requirement.txt.

app = Flask(__name__) # "Flask" is a class and create a Flask application, where "__name__" refers to the current file. So it's basically creating a Flask application from this "app.py" file.

# A Python decorator is a function with the "@" symbol that takes in a function and returns it by adding some functionality.
# "app.route" means mapping the URLs to a specific function that will handle the logic for that URL.
# The URL "/" is associated with the root URL (homepage). For example if our site's domain was "www.example.org" and we want to add routing to "www.example.org/hello", we would use "/hello".
# Here is to define the "/" route of app as returning the contents of index.html, i.e., here is code I want the server to execute whenever a user visits, "domain_name/".
# So "@app.route("/")" tells Flask that if an HTTP request comes in for "/", the following "index" function should be run, so "/" route will be designed to return index.html.
@app.route("/")
def index(): # Because they are accessing a preset page, also known as the index of the site, it's reasonable to call index by convention.
    # When you submit a form with method="get", Flask provides us with a special variable called "request.args", and in there is all of the key value pairs (URL/?key1=value1&key2=value2&...) that might have come in via the URL.
    if "your_name" in request.args: # Check if the key "your_name" exists in "request.args" and has a value. (In "URL/?key=value", if "key" is "your_name", the key "your_name" exists)
        name = request.args["your_name"]
    else:
        name = "world"
    return render_template("index.html", placeholder=name) # "render_template" is used to create pages on your site that mix HTML and Python together.
                                                           # "render_template" will go find that file in templates folder by convention.
                                                           # It will open it up and then it will spit the whole thing out to the browser,
                                                           # so I can keep all HTML files in the templates folder, and all Python code in this place.
                                                           # Note that if I have CSS files, JavaScript files, and images used by the templates, I keep them in another folder called static.
                                                           # "render_template" takes not just one argument (the name of the template you want to spit out),
                                                           # but it takes all of the placeholders you want to plug in.

    # return render_template("index.html", placeholder=request.args.get("your_name", "world"))
    # You can do the same thing by just running this line and leaving out the above.
    # Pass an argument to "request.args.get". By default, if there is no key called "your_name" in "request.args", it is just going to return "None". It can also take a default value, like "world" here.
