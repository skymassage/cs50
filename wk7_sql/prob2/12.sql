-- Write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
-- Method 1: use the command "INTERSECT"
SELECT movies.title FROM people, stars, movies WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND people.name = "Bradley Cooper"
INTERSECT
SELECT movies.title FROM people, stars, movies WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND people.name = "Jennifer Lawrence";

-- Method 2: find the movies starring Bradley Cooper which also include Jennifer Lawrence
--SELECT title FROM movies, stars, people WHERE movies.id = stars.movie_id AND people.id = stars.person_id
--AND name = 'Bradley Cooper'
--AND title IN (
--    SELECT title FROM movies, stars, people WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND name = 'Jennifer Lawrence'
--);

-- Method 3: first find movies starring Jennifer Lawrence, and then select these movies that include Bradley Cooper.
--SELECT title FROM movies WHERE id IN (
--    SELECT movie_id FROM (
--        SELECT movie_id FROM stars, people WHERE stars.person_id = people.id AND name = 'Bradley Cooper'
--        )
--    WHERE movie_id IN (
--        SELECT movie_id FROM stars, people WHERE stars.person_id = people.id AND name = 'Jennifer Lawrence'
--        )
--);