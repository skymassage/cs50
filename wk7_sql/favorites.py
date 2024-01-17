# Searches database popularity of a problem
from cs50 import SQL

db = SQL("sqlite:///favorites.db")  # Open database: "db = SQL("sqlite:///favorites.db")" provide Python the location of the database file.

favorite = input("Favorite problem: ")

# This SQL command within the quotation marks is passed to "db.execute".
# Note that "rows" is returned as a list of dictionaries when using "SELECT". So if your query returns nothing, like no matches, you will get back an empty list.
# Don't use f-strings for SQL queries in "", because it just pastes the whole strings intactly, some pieces of which may cause generating unnecessary SQL commands that are even harmful to cybersecurity, such as SQL injection attacks.
# You should use a placeholder which can address these suspicious strings. In the world of SQL, single question mark '?' are used as placeholders.
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem = ?", favorite)
#rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")  # If you are not sure about the name of your favorite problem, you can use "LIKE" and "%".

row = rows[0]  # In this case, there is only one result, one row, returned to the rows list as a dictionary.
print(rows)
print(row["COUNT(*)"])

rows = db.execute("SELECT * FROM favorites WHERE problem = ?", favorite)  # The output is a list where each element is a dict and has one or more key-value pairs.
print(rows)

rows = db.execute("SELECT * FROM favorites WHERE problem LIKE ?", "%" + "ari" + "%") # This is how to use % in "db.execute" to find that there is "ari" in the middle of the problem name, i.e., Mario.
print(rows)
