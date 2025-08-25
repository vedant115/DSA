WITH Daily AS (
  SELECT visited_on, SUM(amount) AS total_amount
  FROM Customer
  GROUP BY visited_on
)
SELECT d1.visited_on, SUM(d2.total_amount) amount, ROUND(AVG(d2.total_amount), 2) average_amount 
FROM Daily d1
JOIN Daily d2
  ON DATEDIFF(d1.visited_on, d2.visited_on) BETWEEN 0 AND 6
GROUP BY d1.visited_on
HAVING COUNT(d2.visited_on) = 7
ORDER BY d1.visited_on;