/*

https://leetcode.com/problems/monthly-transactions-i/description/?envType=study-plan-v2&envId=top-sql-50

Table: Transactions

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| country       | varchar |
| state         | enum    |
| amount        | int     |
| trans_date    | date    |
+---------------+---------+
id is the primary key of this table.
The table has information about incoming transactions.
The state column is an enum of type ["approved", "declined"].
 

Write an SQL query to find for each month and country, the number of transactions and their total amount, the number of approved transactions and their total amount.

Return the result table in any order.

*/

# Write your MySQL query statement below

with transaction_table as (
select *, 
year(trans_date) as year, 
month(trans_date) as month, 
case
    when state = 'approved' then amount
    when state = 'declined' then null
end as approved_amount
from Transactions
)
select concat(year , '-' , lpad(month, 2, '0')) as month, 
country, 
count(trans_date) as trans_count,
count(approved_amount) as approved_count,
sum(amount) as trans_total_amount,
ifnull(sum(approved_amount), 0) as approved_total_amount
from transaction_table
group by country, year, month
