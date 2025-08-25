SELECT results
FROM (
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m
    ON u.user_id = m.user_id
    GROUP BY u.user_id
    ORDER BY COUNT(m.movie_id) DESC, u.name ASC
    LIMIT 1
) AS t1

UNION ALL

SELECT results
FROM (
    SELECT m.title AS results
    FROM Movies m
    JOIN MovieRating mr
    ON m.movie_id = mr.movie_id
    WHERE MONTH(mr.created_at) = 2 AND YEAR(mr.created_at) = 2020
    GROUP BY mr.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
) AS t2;
