/*
https://leetcode.com/problems/second-highest-salary/

Write a SQL query to get the second highest salary from the Employee table.

Table: Employee
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

For example, given the above Employee table, 
the query should return 200 as the second highest salary. 
If there is no second highest salary, then the query should return null.
*/

SELECT MAX(E.SALARY) AS SecondHighestSalary
FROM EMPLOYEE AS E
WHERE E.SALARY NOT IN
(
    SELECT MAX(EM.SALARY)
    FROM EMPLOYEE AS EM
);

WITH DistinctSalary as (
    SELECT DISTINCT salary 
    from Employee
),
RankedSalary AS (
    SELECT salary, rank() OVER (ORDER BY salary DESC) AS ranking
    FROM DistinctSalary
)
DELETE
    CASE
        WHEN MAX(ranking) >= 2 THEN (SELECT salary FROM RankedSalary WHERE ranking = 2)
        ELSE NULL
    END AS SecondHighestSalary
FROM RankedSalary;