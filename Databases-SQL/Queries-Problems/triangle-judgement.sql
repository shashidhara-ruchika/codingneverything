/*

https://leetcode.com/problems/triangle-judgement/description/?envType=study-plan-v2&envId=top-sql-50

Table: Triangle

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
 

Report for every three line segments whether they can form a triangle.

Return the result table in any order.

*/

# Write your MySQL query statement below

select *,
case 
    when x + y > z and y + z > x and z + x > y then 'Yes'
    else 'No'
end as triangle
from Triangle 

