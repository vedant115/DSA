SELECT activity_date day, COUNT(DISTINCT user_id) active_users 
FROM Activity
WHERE activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY) AND activity_date <= '2019-07-27'
GROUP BY day;