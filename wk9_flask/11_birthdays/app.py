import os
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

app = Flask(__name__)

app.config["TEMPLATES_AUTO_RELOAD"] = True

db = SQL("sqlite:///birthdays.db")

@app.after_request  # This decorator is used to specify a function that should be run after each request to the server.
def after_request(response):
    # HTTP headers are part of the HTTP protocol that provide additional information about the request or response.

    # A request header is sent by the client to the server, including information like the type of browser making the request,
    # the type of data the client can accept, the language preference, and more.
    # The HTTP message below shows a few request headers after a GET request:
    '''
    GET /home.html HTTP/1.1
    Host: developer.mozilla.org
    User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:50.0) Gecko/20100101 Firefox/50.0
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
    Accept-Language: en-US,en;q=0.5
    Accept-Encoding: gzip, deflate, br
    Referer: https://developer.mozilla.org/testpage.html
    Connection: keep-alive
    Upgrade-Insecure-Requests: 1
    If-Modified-Since: Mon, 18 Jul 2016 02:36:04 GMT
    If-None-Match: "c561c68d0ba92bbeb8b0fff2a9199f722e3a621a"
    Cache-Control: max-age=0
    '''

    # A response header is sent by the server to the client, including information like the date, the server type,
    # the type of data in the response, and instructions for caching the response.
    # The following shows a few response and representation headers after a GET request.
    '''
    200 OK
    Access-Control-Allow-Origin: *
    Connection: Keep-Alive
    Content-Encoding: gzip
    Content-Type: text/html; charset=utf-8
    Date: Mon, 18 Jul 2016 16:06:00 GMT
    Etag: "c561c68d0ba92bbeb8b0f612a9199f722e3a621a"
    Keep-Alive: timeout=5, max=997
    Last-Modified: Mon, 18 Jul 2016 02:36:04 GMT
    Server: Apache
    Set-Cookie: mykey=myvalue; expires=Mon, 17-Jul-2017 16:06:00 GMT; Max-Age=31449600; Path=/; secure
    Transfer-Encoding: chunked
    Vary: Cookie, Accept-Encoding
    X-Backend-Server: developer2.webapp.scl3.mozilla.com
    X-Cache-Info: not cacheable; meta data too large
    X-kuma-revision: 1085259
    x-frame-options: DENY
    '''

    # Caching is the process of storing certain data for future use.
    # The HTTP cache stores a response associated with a request and reuses the stored response for subsequent requests.
    # In the web development, cache could be web pages, images, or any other type of content that a user might request from a server.
    # The main purpose of caching is to make data retrieval faster.
    # When a client requests a resource that has been cached, it can be served from the cache instead of the original server.
    # This reduces the load on the server and decreases the time it takes for the client to receive the requested resource.
    # The most typical example is when the browser itself stores a cache for browser requests.
    # However, caching can also lead to issues when the data changes on the server, but the client still has an old cached version.

    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate" # Tell the client not to cache the response, not to store it, and to validate it with the server before using it.
    # The "Cache-Control" header is used in HTTP responses to define how, or even if, the client should cache the response. It's a way for the server to control the caching behavior.

    # "no-cache" means that a cached copy of the response can be stored, but cache should validate the response with the origin server before reuse.
    # This is done to ensure that the client always has the most up-to-date version of the resource.
    # If the server indicates that the cached copy is still fresh, then it can be used;
    # otherwise, a new copy must be fetched from the server.

    # "no-store" instructs the browser (or any other intermediate caches like a CDN) not to store a copy of the resource under any circumstances.
    # When the "no-store" is present, the browser will always request the specific resource from the server,
    # ensuring that it's getting the most up-to-date version. This is useful for sensitive data that should not be stored in the cache,
    # such as banking information or personal details.

    # "must-revalidate" tells the client that once a resource becomes old, caches must not use their old copy without successful validation on the origin server.
    # It means that when the cache has a stored copy of the resource that is no longer fresh, it must check with the server to see if the copy is still good to use.
    # If the server says it's okay, the cached copy can be used. If not, a new copy must be fetched from the server.
    # This ensures that users always receive the most up-to-date content.

    response.headers["Expires"] = 0 # Tell the client that the response is already expired and should not be used without revalidation.
    # The "Expires" HTTP header contains the date/time after which the response is considered expired.
    # Invalid expiration dates with value "0" represent a date in the past and mean that the resource is already expired.

    response.headers["Pragma"] = "no-cache" # An obsolete directive that's similar to "Cache-Control": "no-cache". It's included for compatibility with HTTP/1.0 clients.

    return response # Return the modified response. This ensures that every time a client makes a request, they get a fresh response from the server, not a cached one.


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Each field cannot be empty.
        if not request.form.get("name") or not request.form.get("month") or not request.form.get("day"):
            return redirect("/")

        # TODO: Add the user's entry into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?);", request.form.get("name"), request.form.get("month"), request.form.get("day"))
        return redirect("/")

    else:
        # TODO: Display the entries in the database on index.html
        rows = db.execute("SELECT * FROM birthdays;")
        return render_template("index.html", rows=rows)
