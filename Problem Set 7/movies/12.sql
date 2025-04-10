SELECT title FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id

  WHERE name IN ('Jennifer Lawrence', 'Bradley Cooper')
  GROUP BY title
  HAVING COUNT(title) > 1;
