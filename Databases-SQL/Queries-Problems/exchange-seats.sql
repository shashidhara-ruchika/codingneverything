/*
https://leetcode.com/problems/exchange-seats/
*/

/*
Table: Seat

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
id is a continuous increment.
 

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by id in ascending order.

The result format is in the following example.

 

Example 1:

Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.

*/

# Write your MySQL query statement below

select s2.id, s1.student
from seat s1
join seat s2
on 
case
    when s1.id % 2 = 0 then s1.id = s2.id + 1
    when s1.id % 2 = 1 and s1.id = (select max(id) from seat) then s1.id = s2.id
    when s1.id % 2 = 1 then s2.id = s1.id + 1
end
order by s2.id

select 
	id,
	ifnull(if(mod(id, 2) = 1, Lead(student, 1) OVER (ORDER BY id ASC), lag(student, 1) OVER (ORDER BY id ASC)), student) as student
from seat

SELECT
	id,
	IFNULL(IF(MOD(id, 2) = 1, LEAD(student) OVER (), LAG(student) OVER ()), student) as student
FROM seat