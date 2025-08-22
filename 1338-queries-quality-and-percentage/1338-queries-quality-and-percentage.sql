SELECT q.query_name, ROUND(AVG(q.rating / q.position), 2) quality, ROUND(SUM(q.rating < 3)/COUNT(q.rating) * 100.0, 2) poor_query_percentage 
FROM Queries q
GROUP BY q.query_name;