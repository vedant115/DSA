SELECT 
    ROUND(COUNT(DISTINCT a1.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity a
JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) a1
  ON a.player_id = a1.player_id
WHERE DATEDIFF(a.event_date, a1.first_login) = 1;
