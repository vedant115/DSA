SELECT ROUND(SUM(i1.tiv_2016), 2) tiv_2016
FROM Insurance i1
WHERE i1.tiv_2015 IN
(
    SELECT tiv_2015 
    FROM Insurance i2
    WHERE i1.pid <> i2.pid
) AND
(i1.lat, i1.lon) NOT IN
(
    SELECT i3.lat, i3.lon
    FROM Insurance i3
    WHERE i1.pid <> i3.pid
);