SELECT a.machine_id, ROUND(( 
    (SELECT SUM(timestamp)
    FROM Activity a1
    WHERE a1.activity_type = 'end' AND a1.machine_id = a.machine_id)  - 
    (SELECT SUM(timestamp)
    FROM Activity a2
    WHERE a2.activity_type = 'start' AND a2.machine_id = a.machine_id)) / (COUNT(a.machine_id)/2), 3)processing_time 
FROM Activity a
GROUP BY machine_id;
