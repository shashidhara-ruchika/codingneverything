/*

https://leetcode.com/problems/find-followers-count/submissions/1280106985/?envType=study-plan-v2&envId=top-sql-50

# Write your MySQL query statement below

select user_id, count(follower_id) as followers_count 
from Followers
group by user_id
order by user_id

*/