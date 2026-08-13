WITH temp AS (
    SELECT u.name, COUNT(*) AS cnt
    FROM Users u
    JOIN MovieRating mr
        ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
),
user_result AS (
    SELECT name
    FROM temp
    ORDER BY cnt DESC, name
    LIMIT 1
),
movie_result AS (
    SELECT m.title
    FROM Movies m
    JOIN MovieRating mr
        ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01'
      AND mr.created_at < '2020-03-01'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title
    LIMIT 1
)
SELECT name AS results
FROM user_result

UNION ALL

SELECT title AS results
FROM movie_result;