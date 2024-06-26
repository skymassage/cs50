----------------------------------------------------------------------Thees command are SQLite specified
sqlite3 <database.db> -- use the third version of SQLite to create or get into the SQL database with a filename extension "db".
.mode csv -- put sqlite3 into CSV mode.
.import <file.csv> <table> -- import data from the CSV file into the table, where <table> is the name of the table you create, and this table is added to <database.db>,
                           -- when accessing the same database you do not re-import again using this command,
                           -- note that to import data from the CSV file, you must execute ".mode csv" before ".import", otherwise all columns will be in one column without separation and you can't specify the column.
.quit .exit Ctrl+D -- exit from sqlite3.
.tables -- list all of the tables in the database
.schema -- display the structure of the database, i.e. the structures of each table.
.schema <table> -- display the structure of <table>.
.timer on|off: -- Turn SQL timer on or off
               -- SQL timer keeps track of how long each command takes.
               -- Run time has three type: user time, system time, real time.
               -- Real time is wall clock time - the actual amount of time it took to run the command.
               -- User time is how much work the CPU did to run to run the command's code.
               -- Syetem time is how much work the CPU had to do to handle 'system overhead' type tasks 
               -- (such as allocating memory, file I/O, ect.) in order to support the running command.
               
.read <file.sql> -- run the commands of <file.sql> in SQLite.

.headers <on/off> -- Turn table headers display on or off
.mode <tabular_output_mode> -- <tabular_output_mode> has four modes: column, table, markdown, box. 
                            -- These modes will turn ".header" on if it has not been previously set.

---------------------------------------------------------------------- Use the following commands outside of sqlite3:
cat <file>.sql | sqlite3 <database>.db -- Execute all queries in <file>.sql on <database>.db
cat <file>.sql | sqlite3 <database>.db > <output>.txt -- Redirect the output of all queries in <file>.sql to a text file called <output>.txt. 

----------------------------------------------------------------------SQL commands for database
-- Semicolon ';' indicates the end of the command. If you click "Enter" withoint ';', the command will continues to the next line until you click "Enter" with a ';'.

SELECT <column1, column2, ...> FROM <table>; -- display the column1, column2, etc. (each column's title is at the first row ) that you want in the table.
ex: SELECT language, problem FROM favorites; --  will iterate and print every row in the cloumns "language" and "problem" of the table "favorites".
    SELECT * FROM favorites; -- will iterate and print every row in each column of the table "favorites". ('*' is just shorthand for every column.)

SELECT UPPER(<column1>), UPPER(<column2>), ... FROM <table>; -- Change the all letters in the column1, column2, etc. to uppercase.
SELECT LOWER(<column1>), UPPER(<column2>), ... FROM <table>; -- Change all letters in column1 to lowercase, all letters in column2 to uppercase, and so on.

SELECT COUNT(<column1>), COUNT(<column2>), ... FROM <table>; -- displays the number of rows from the column1, column2, etc. of the database table.
SELECT COUNT(*) FROM table; -- display the number of rows from the database table (no specified column).

SELECT DISTINCT(<column>) FROM <table>; -- display the all distinct rows from the specified column of the table.

SELECT COUNT(DISTINCT(<column>)) FROM <table>; -- return the number of rows from "SELECT DISTINCT(<column>) FROM table".

-- You can use "As <new_column>" to rename the column title you display, for example:
SELECT <column> AS <new_column> FROM <table>;
SELECT <column1> AS <new_column1>, <column2> AS <new_column2> FROM <table>; -- rename two column title.
SELECT COUNT(<column>) AS <new_column> FROM <table>;
SELECT DISTINCT(<column>) AS <new_column> FROM <table;>
SELECT COUNT(DISTINCT(<column>)) AS <new_column> FROM <table>;

-- Other command
WHERE -- Add a Boolean expression to filter our data
LIKE -- Filter responses more loosely (use "LIKE" when wanting to roughly match something)
ORDER BY -- Order the results based on a specified column
LIMIT -- Limit the number of results returned by a query
GROUP BY -- Group results by a specified column ("WHERE" is applied before "GROUP BY")
HAVING -- Allow for additional constraints based on the number of results. 
       -- If you use "HAVING", you must include "GROUP BY" and "HAVING" is applied after "GROUP BY".

----------------------------------------------------------------------SQL command examples for favorites.csv and favorites.db

SELECT * FROM favorites WHERE language = 'Python'; -- display the rows of "Python" in "language" column, and note that for the datatype text, use the apostrophe ' instead of double quotes ".

SELECT COUNT(*) FROM favorites WHERE language = 'Python'; -- display how many people like "Python" in "language" column.

SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Tideman'; -- display how many people like "C" language and problem "Tideman".

SELECT * FROM favorites ORDER BY language; -- display rows sorted alphabetically by "language", if the column's values are numeric, the order is sorted numerically.
SELECT * FROM favorites ORDER BY language ASC; -- display rows sorted alphabetically by "language", in ascending ("ASC") order, and default is "ASC".
SELECT * FROM favorites ORDER BY language DESC; -- display rows sorted alphabetically by "language", in descending ("DESC") order.
SELECT * FROM favorites ORDER BY problem, language; -- display rows sorted alphabetically, sorted first by "problem" and then by "language".
SELECT * FROM favorites ORDER BY problem DESC, language DESC; -- display rows in descending alphabetical order, sorted first by "problem" and then by "language".
-- If the order is sorted alphabetically, it will be sorted by the first letter, then the second order, and so on.
-- So it is not quite useful, if the strings in a column except the last column are almost unique when sorting more than one column.
-- Note that it sort based on ASCII, if the string contains numbers or symbols instead of just alphabet.

SELECT * FROM favorites GROUP BY language; -- only display the rows with the first occurrence of each "language".
SELECT * FROM favorites GROUP BY language HAVING language="Python"; -- display the row which includes language="Python" in "SELECT * FROM favorites GROUP BY language".

SELECT language, COUNT(*) FROM favorites GROUP BY language; -- it displays a two column table where the first column is language and the second column is the count thereof from this data set.
                                                            -- "GROUP BY language" means that shows "C" only once, "Python" only once, and so on.
                                                            -- Finally, group all of the identical values together, but keep track of how many of them there are.

SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*); -- same as the previous example, but the order is sorted numerically according to "COUNT(*)".

SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC LIMIT 2; -- similar to the previous example, but show first 2 popular language using "DESC" and "LIMIT 2".

INSERT INTO <table> (<column1, colunm2>, ...) VALUES(<value1>, <value2>, ...) -- insert into a SQL database
INSERT INTO favorites (language, problem) VALUES ('C', 'cash'); -- insert the values "C" and "Filter" into the "language" and "problem" columns of "favorites".

UPDATE <table> SET <column> = <value> WHERE <condition>; -- update the specified column of the table.
UPDATE favorites SET language = 'Python' WHERE language = 'Scratch'; -- in "language" column, overwrite all "Scratch" to "Python",
                                                                     -- and it should display nothing when checking with "SELECT * FROM favorites WHERE title = 'Scratch';".
                                                                     -- Note that don't forget this part "WHERE condition", for example,
                                                                     -- "UPDATE favorites SET language = 'Python';" will overwrite all values in "language" column to "Python".

DELETE FROM <table> WHERE <condition>; -- delete the specified parts of the data.
DELETE FROM favorites WHERE problem = 'Mario'; -- delete the rows whose "problem" column is "Mario".
DELETE FROM favorites -- delete all of the data.

DROP TABLE <table_name>; -- remove the table

-- When talking about SQL column names, they are case-insensitive.
ex: SELECT LaNGUAGe FROM favorites;
    SELECT * FROM favorites WHERE LanGuaGe = 'Python';
    SELECT * FROM favorites ORDER BY LANGuage;

---------------------------------------------------------------In SQLite, there are five datatypes and two special constraints

BLOB -- (Binary Large Object): Any other binary data that we may want to store in our database (Ex. an image)
INTEGER -- An integer
NUMERIC -- A more general form of numeric data (Ex. A date or boolean value)
REAL -- Any real number
TEXT -- For strings of text

NOT NULL -- ensure the values in a column are not NULL
UNIQUE -- ensures all values in a column or a group of columns are distinct from one another or unique.

----------------------------------------------------------------------SQL command examples for shows.db
-- First, use ".schema" to investigate the structure of the database.

SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') ORDER BY title LIMIT 10;
-- Order the comedy show titles alphabetically, and display the first 10.

SELECT title FROM shows WHERE title IN (SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') LIMIT 10) ORDER BY title;
-- Display the first 10 comedy show titles alphabetically.

-- Display the show titles related to Steve Carell, we can divide this command into three steps as below:
1. SELECT id FROM people WHERE name = 'Steve Carell';
2. SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell');
3. SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell'));

-- Use "JOIN ... ON ..." to combine tables as below:
ex: SELECT * FROM shows JOIN genres ON shows.id = genres.show_id LIMIT 10; -- (You can omit "shows." and "genres." 
                                                                           -- if you are familiar with these two tables. 
                                                                           -- However, if the names of the columns are same, 
                                                                           -- you should use them to specify which table)
    SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE title = 'The Office';
    SELECT * FROM shows JOIN stars ON shows.id = stars.show_id JOIN ratings ON ratings.show_id = shows.id LIMIT 10;
    SELECT COUNT(*) FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating > 9.5;
    SELECT ratings.rating, COUNT(*) FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating > 9.5 GROUP BY rating;
-- You also can combine tables without "JOIN ... ON ..." as below:
ex: SELECT * FROM shows, genres WHERE shows.id = genres.show_id LIMIT 10;
    SELECT * FROM shows, ratings WHERE shows.id = ratings.show_id AND title = 'The Office';
    SELECT * FROM shows, stars, ratings WHERE shows.id = stars.show_id AND ratings.show_id = shows.id LIMIT 10;
    SELECT COUNT(*) FROM shows, ratings WHERE shows.id = ratings.show_id AND rating > 9.5;
    SELECT ratings.rating, COUNT(*) FROM shows, ratings WHERE shows.id = ratings.show_id AND rating > 9.5 GROUP BY rating;

-- Here are the three different ways to display the show titles related to Steve Carell (but in slightly different order):
SELECT shows.title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell'));
SELECT shows.title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id WHERE name = 'Steve Carell';
SELECT shows.title FROM people, stars, shows WHERE people.id = stars.person_id AND stars.show_id = shows.id AND name = 'Steve Carell';

-- If you're not sure about someone's name but have an impression, you can use the wildcard '%' operator and "LIKE".
SELECT * FROM people WHERE name LIKE 'Steve%'; --  if you forgot the last name of Steve Carell
SELECT * FROM people WHERE name LIKE '%Carell'; -- if you forgot the first name of Steve Carell
SELECT * FROM people WHERE name LIKE 'Steve C%'; --  if you forgot the last name of Steve Carell, but remember it starts with 'C'.
SELECT * FROM people WHERE name LIKE 'stEVe c%'; -- this is case-insensitive.

-- If you want to search on certain columns frequently, you can search the columns faster by creating indexes with the following syntax before searching:
CREATE INDEX <name> on <table> (<column1>, ...); -- this will create a data structure called a B Tree, a data structure that looks similar to a binary tree. However, unlike a binary tree, there can be more than two child notes.
ex: CREATE INDEX title_index on shows (title); -- this tells sqlite3 to create an index and perform some special under-the-hood optimization relating to this column "title".
    -- Compare the running time of "SELECT * FROM shows WHERE title = 'The Office';" before and after "CREATE INDEX title_index on shows (title);"

----------------------------------------------------------------------
-- One example of the creating table command
CREATE TABLE IF NOT EXISTS <table_name> (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
   	<column1> [data_type] NOT NULL UNIQUE,
	<column2> [data_type] DEFAULT 0
);
-- Attempting to create a table that already exists will result in an error, so "IF NOT EXISTS" is the option to create a new table if it does not exist.
-- id: It is often helpful to have an number that allows us to uniquely identify each row in a table. 
--     Here we have specified that the data type of id is integer, and also id is our primary key, meaning it is our unique identifier. 
--     We have additionally specified that it will "AUTOINCREMENT", which means we will not have to provide an id every time we add to the table because it will be done automatically.
-- DEFAULT: Provides a default value if no value is given. So "DEFAULT 0" means to set all values in <column2> to "0".
-- NOT NULL: Makes sure a value is provided
-- PRIMARY KEY: Indicates this is the primary way of searching for a row in the database
-- UNIQUE: Ensures that no two rows have the same value in that column.

-- The examples for roster.db
CREATE TABLE students (id INTEGER, student_name TEXT, PRIMARY KEY(id));
CREATE TABLE houses (id INTEGER, house TEXT, head TEXT, PRIMARY KEY(id));
CREATE TABLE assignments (student_id INTEGER, house_id INTEGER, FOREIGN KEY(student_id) REFERENCES students(id), FOREIGN KEY(house_id) REFERENCES houses(id), PRIMARY KEY(student_id, house_id));
