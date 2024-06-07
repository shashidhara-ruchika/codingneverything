/*
https://leetcode.com/problems/immediate-food-delivery-ii/description/?envType=study-plan-v2&envId=top-sql-50

Table: Delivery

+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id is the column of unique values of this table.
The table holds information about food delivery to customers that make orders at some date and specify a preferred delivery date (on the same order date or after it).
 

If the customer's preferred delivery date is the same as the order date, then the order is called immediate; otherwise, it is called scheduled.

The first order of a customer is the order with the earliest order date that the customer made. It is guaranteed that a customer has precisely one first order.

Write a solution to find the percentage of immediate orders in the first orders of all customers, rounded to 2 decimal places.

*/

# Write your MySQL query statement below

with customer_first_order as (
select customer_id, min(order_date) as first_order
from Delivery
group by customer_id
), 
immediate_delivery as (
select delivery_id, 
case 
    when order_date = customer_pref_delivery_date then 1.0
    else 0.0
end as is_immediate
from Delivery d
join customer_first_order f
on d.customer_id = f.customer_id and d.order_date = f.first_order
)
select round(sum(is_immediate) * 100 / count(is_immediate), 2) as immediate_percentage 
from immediate_delivery