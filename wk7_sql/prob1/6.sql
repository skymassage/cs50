-- Write a SQL query that lists the names of songs that are by Post Malone.
SELECT songs.name FROM songs JOIN artists ON artists.id = songs.artist_id WHERE artists.name = 'Post Malone';
-- SELECT songs.name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE artists.name = 'Post Malone');