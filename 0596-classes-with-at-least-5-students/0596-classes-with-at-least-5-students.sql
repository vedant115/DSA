SELECT c.class FROM
(SELECT class, COUNT(student) cnt
FROM Courses
GROUP BY class
HAVING cnt >=5 ) c;