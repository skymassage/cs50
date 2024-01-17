-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT movie_id FROM stars, people WHERE stars.person_id = people.id AND people.name = 'Kevin Bacon' AND birth = 1958
    )
) AND name != 'Kevin Bacon' GROUP BY name;