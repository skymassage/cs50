-- Write a SQL query to list the names of all people who starred in Toy Story.
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story'));
--SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id WHERE title = 'Toy Story';
--SELECT name FROM people, stars, movies WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND title = 'Toy Story';