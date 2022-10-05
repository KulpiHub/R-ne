SELECT title FROM movies
JOIN people ON stars.person_id=people.id
JOIN stars ON stars.movie_id=movies.id
WHERE people.name="Johnny Depp"
AND title IN (
    SELECT title FROM movies
    JOIN people ON stars.person_id=people.id
    JOIN stars ON stars.movie_id=movies.id
    WHERE people.name="Helena Bonham Carter"
);