-- https://leetcode.com/problems/product-sales-analysis-i/description/?envType=study-plan-v2&envId=top-sql-50

/*
Table: Sales

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) is the primary key (combination of columns with unique values) of this table.
product_id is a foreign key (reference column) to Product table.
Each row of this table shows a sale on the product product_id in a certain year.
Note that the price is per unit.
 

Table: Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id is the primary key (column with unique values) of this table.
Each row of this table indicates the product name of each product.
 

Write a solution to report the product_name, year, and price for each sale_id in the Sales table.

Return the resulting table in any order.
*/

# Write your MySQL query statement below

select p.product_name, s.year, s.price
from Product p 
join Sales s
on p.product_id = s.product_id


/*

Write a solution to select the product id, year, quantity, and price for the first year of every product sold.

Return the resulting table in any order.

*/

# Write your MySQL query statement below
select product_id , year as first_year, quantity, price
from Sales
where (product_id , year) in (
select product_id , min(year) 
from Sales 
group by product_id 
)
