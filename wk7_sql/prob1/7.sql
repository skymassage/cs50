-- Write a SQL query that returns the average energy of songs that are by Drake.
SELECT AVG(songs.energy) FROM songs JOIN artists ON artists.id = songs.artist_id WHERE artists.name = 'Drake';
--SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE artists.name = 'Drake');