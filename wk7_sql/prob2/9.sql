-- Write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id WHERE year = 2004 ORDER BY birth;
-- SELECT name FROM people, stars, movies WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND year = 2004 ORDER BY birth;