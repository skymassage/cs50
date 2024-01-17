# There must be no roaster.db here before running this program, otherwise errors will occur.
# But first run the following commands in the terminal:
#------------------------------method 1
# sqlite3 roster.db
# .mode csv
# .import roster.csv roster
# .read roster.sql
# .quit
#------------------------------method 2
# sqlite3 roster.db
# .mode csv
# .import roster.csv roster
# .quit
# cat roster.sql | sqlite3 roster.db
from cs50 import SQL

db = SQL("sqlite:///roster.db")

rows = db.execute("SELECT house, head FROM roster GROUP BY house")
for row in rows:
    db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", row["house"], row["head"])

rows = db.execute("SELECT * FROM roster")
for row in rows:
    db.execute("INSERT INTO students (id, student_name) VALUES (?, ?)", row["id"], row["student_name"])

rows = db.execute("SELECT students.id AS student_id, houses.id AS house_id FROM roster JOIN students ON students.student_name = roster.student_name JOIN houses ON houses.house = roster.house")
for row in rows:
    db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, ?)", row["student_id"], row["house_id"])

# Use the following commands sqlite3 to check the results:
# SELECT * FROM roster;
# SELECT * FROM students;
# SELECT * FROM houses
# SELECT students.id AS student_id, houses.id AS house_id FROM roster JOIN students ON students.student_name = roster.student_name JOIN houses ON houses.house = roster.house;
# SELECT * FROM assignments;