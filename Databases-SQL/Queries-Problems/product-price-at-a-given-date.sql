/*

https://leetcode.com/problems/product-price-at-a-given-date/?envType=study-plan-v2&envId=top-sql-50

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key (combination of columns with unique values) of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
 

Write a solution to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.

Return the result table in any order.

*/

# Write your MySQL query statement belo as date
with max_price as ( 
select product_id, max(change_date) as date
from Products 
where change_date <= '2019-08-16'
group by product_id 
)
select distinct product_id, 10 as price
from Products
where product_id not in (select distinct product_id from max_price)
union 
select p.product_id, p.new_price as price
from max_price mp
join Products p
on p.product_id = mp.product_id and p.change_date = mp.date
