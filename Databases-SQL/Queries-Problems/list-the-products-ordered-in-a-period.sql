/*

https://leetcode.com/problems/list-the-products-ordered-in-a-period/submissions/1297174569/?envType=study-plan-v2&envId=top-sql-50

Table: Products

+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| product_id       | int     |
| product_name     | varchar |
| product_category | varchar |
+------------------+---------+
product_id is the primary key (column with unique values) for this table.
This table contains data about the company's products.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| order_date    | date    |
| unit          | int     |
+---------------+---------+
This table may have duplicate rows.
product_id is a foreign key (reference column) to the Products table.
unit is the number of products ordered in order_date.
 

Write a solution to get the names of products that have at least 100 units ordered in February 2020 and their amount.

Return the result table in any order.

*/

# Write your MySQL query statement below
select product_name, sum(unit) as unit
from Orders o
join Products p
on o.product_id = p.product_id
where order_date between "2020-02-01" and "2020-02-29"
group by o.product_id
having sum(unit) >= 100

