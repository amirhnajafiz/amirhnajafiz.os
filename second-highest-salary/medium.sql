# Write your MySQL query statement below
(SELECT DISTINCT(salary) as SecondHighestSalary
FROM Employee
ORDER BY salary DESC
LIMIT 1
OFFSET 1) UNION (SELECT null as SecondHighestSalary ) LIMIT 1;
