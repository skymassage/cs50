import csv
import datetime
import pytz
import requests
import subprocess
import urllib
import uuid

from flask import redirect, render_template, session
from functools import wraps

# Render message as an apology to user
def apology(message, code=400):
    def escape(s):
        # We want to generate the memes through the URLs in "apology.html", these URLs have their naming rules.
        # Because "message" may include the special characters, so we need to replace them to comply with the naming rule.
        # You can refer to the following page to see  which characters some special characters need to be replaced with:
        # https://github.com/jacebrowning/memegen#special-characters
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code

# Decorate routes to require users to log in before accessing a given route.
# (You can erfer to https://flask.palletsprojects.com/en/3.0.x/patterns/viewdecorators/)
def login_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function

# Use a stocks API to get the current stock quote for a particular stock symbol (e.g., NFLX) .
# Given a "symbol" (e.g., NFLX), "lookup" returns a stock quote for a company in the form of a dict with three keys:
# 1. name: whose value is a str, the name of the company
# 2. price: whose value is a float
# 3. symbol: whose value is a str, a canonicalized (uppercase) version of a stock's symbol,
#            irrespective of how that symbol was capitalized when passed into "lookup".
def lookup(symbol):

    # Prepare API request
    symbol = symbol.upper()
    end = datetime.datetime.now(pytz.timezone("US/Eastern"))
    start = end - datetime.timedelta(days=7)

    # Yahoo Finance API
    url = (
        f"https://query1.finance.yahoo.com/v7/finance/download/{urllib.parse.quote_plus(symbol)}"
        f"?period1={int(start.timestamp())}"
        f"&period2={int(end.timestamp())}"
        f"&interval=1d&events=history&includeAdjustedClose=true"
    )

    # Query API
    try:
        response = requests.get(url, cookies={"session": str(uuid.uuid4())}, headers={"User-Agent": "python-requests", "Accept": "*/*"})
        response.raise_for_status()

        # CSV header: Date,Open,High,Low,Close,Adj Close,Volume
        quotes = list(csv.DictReader(response.content.decode("utf-8").splitlines()))
        quotes.reverse()
        price = round(float(quotes[0]["Adj Close"]), 2)
        return {
            "name": symbol,
            "price": price,
            "symbol": symbol
        }
    except (requests.RequestException, ValueError, KeyError, IndexError):
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"  # ',' means to adds comma to thousand place; ".2f" means to round numbers to the second decimal place.


def qualify(password):
    print(password, type(password))
    if 7 <= len(password) <= 15:
        if password.isalnum():
            digit, upper, lower = False, False, False
            for p in password:
                if p.isdigit() == True:
                    digit = True
                if p.isupper() == True:
                    upper = True
                if p.islower() == True:
                    lower = True

            if digit == True and upper == True and lower == True:
                return
            else:
                return 3
        else:
            return 2
    else:
        return 1  # Use "apology" here doesn't work.
