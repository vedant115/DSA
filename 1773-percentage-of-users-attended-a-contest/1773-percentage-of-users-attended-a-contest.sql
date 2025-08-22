SELECT r.contest_id, ROUND((COUNT(r.user_id) / (SELECT COUNT(*) FROM users)*100), 2) percentage 
FROM register r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
