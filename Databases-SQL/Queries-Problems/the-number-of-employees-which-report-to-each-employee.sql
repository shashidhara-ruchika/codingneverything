/*

https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description/?envType=study-plan-v2&envId=top-sql-50

*/

Table: Employees

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id is the column with unique values for this table.
This table contains information about the employees and the id of the manager they report to. Some employees do not report to anyone (reports_to is null). 
 

For this problem, we will consider a manager an employee who has at least 1 other employee reporting to them.

Write a solution to report the ids and the names of all managers, the number of employees who report directly to them, and the average age of the reports rounded to the nearest integer.

Return the result table ordered by employee_id.

# Write your MySQL query statement below
/*
with Manager_id as (
select distinct reports_to 
from Employees
),
Manager_data as (
select reports_to as manager_id, count(employee_id) as reports_count , round(avg(age)) as average_age 
from Employees
where reports_to in (select reports_to from Manager_id)
group by manager_id
)
select * 
from Manager_data
join Employees
*/

with manager_report as (
select reports_to as manager_id, count(employee_id) as reports_count, round(avg(age)) as average_age 
from Employees
group by reports_to 
having reports_to is not null
)
select e.employee_id, e.name, mr.reports_count, mr.average_age
from Employees e
join manager_report mr
on e.employee_id = mr.manager_id
order by employee_id