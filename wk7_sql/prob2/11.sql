-- Write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
-- starting with the highest rated.
SELECT title FROM movies, stars, people, ratings
WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND movies.id = ratings.movie_id
AND name = 'Chadwick Boseman'
ORDER BY rating DESC LIMIT 5;