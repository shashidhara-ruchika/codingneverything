/*

https://leetcode.com/problems/queries-quality-and-percentage/description/?envType=study-plan-v2&envId=top-sql-50

Table: Queries

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| query_name  | varchar |
| result      | varchar |
| position    | int     |
| rating      | int     |
+-------------+---------+
This table may have duplicate rows.
This table contains information collected from some queries on a database.
The position column has a value from 1 to 500.
The rating column has a value from 1 to 5. Query with rating less than 3 is a poor query.
 

We define query quality as:

The average of the ratio between query rating and its position.

We also define poor query percentage as:

The percentage of all queries with rating less than 3.

Write a solution to find each query_name, the quality and poor_query_percentage.

Both quality and poor_query_percentage should be rounded to 2 decimal places.

Return the result table in any order.

*/


with q as (
select *,
case 
    when rating < 3 then 1.0
    else 0.0
end as is_poor_rating
from Queries
)

select q.query_name, 
round(sum(q.rating / q.position) / count(q.rating), 2) as quality, 
round(sum(q.is_poor_rating) * 100 / count(q.is_poor_rating), 2) as poor_query_percentage 
from q
where q.query_name is not null
group by q.query_name
