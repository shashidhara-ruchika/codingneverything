/*

https://leetcode.com/problems/consecutive-numbers/description/?envType=study-plan-v2&envId=top-sql-50

able: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column.
 

Find all numbers that appear at least three times consecutively.

Return the result table in any order.

*/

# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums 
from Logs l1
join Logs l2
on l1.id = l2.id - 1
join Logs l3
on l2.id = l3.id - 1
where l1.num = l2.num and l2.num = l3.num
