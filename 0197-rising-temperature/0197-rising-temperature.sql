SELECT t1.id 
FROM Weather t1
JOIN Weather t2
WHERE DATEDIFF(t1.recordDate, t2.recordDate) = 1 AND t1.temperature > t2.temperature;