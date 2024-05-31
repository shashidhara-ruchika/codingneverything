-- https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=top-sql-50

/*
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
 

Write a solution to find managers with at least five direct reports.

Return the result table in any order.
*/

# Write your MySQL query statement below

with manager_reportees_count as (
select m.id, m.name, count(e.id) as count_reportees
from Employee e
join Employee m
on e.managerId = m.id
group by m.id
)
select name
from manager_reportees_count
where count_reportees >= 5