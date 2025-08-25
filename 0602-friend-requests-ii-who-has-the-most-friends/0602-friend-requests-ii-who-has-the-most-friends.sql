SELECT m.id, SUM(m.num) num
FROM(
    SELECT requester_id id, COUNT(accepter_id) num
    FROM RequestAccepted
    GROUP BY requester_id
    UNION All
    SELECT accepter_id id, COUNT(requester_id) num
    FROM RequestAccepted
    GROUP BY accepter_id
) m
GROUP BY m.id
ORDER BY num DESC
LIMIT 1;
