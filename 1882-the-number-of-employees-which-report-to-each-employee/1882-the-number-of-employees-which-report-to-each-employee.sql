SELECT e1.employee_id, e1.name, COUNT(e2.reports_to) reports_count , ROUND(AVG(e2.age), 0) average_age 
FROM Employees e1
JOIN Employees e2
ON e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY employee_id;