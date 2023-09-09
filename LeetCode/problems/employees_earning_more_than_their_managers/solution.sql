# Write your MySQL query statement below

SELECT a.name as Employee
FROM Employee AS a, Employee AS b
WHERE a.managerId = b.id
AND a.salary > b.salary
;