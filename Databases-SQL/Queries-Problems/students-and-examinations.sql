-- https://leetcode.com/problems/students-and-examinations/submissions/1273633702/?envType=study-plan-v2&envId=top-sql-50

/*
Table: Students

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID and the name of one student in the school.
 

Table: Subjects

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key (column with unique values) for this table.
Each row of this table contains the name of one subject in the school.
 

Table: Examinations

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
 

Write a solution to find the number of times each student attended each exam.

Return the result table ordered by student_id and subject_name.
*/

# Write your MySQL query statement below
/*
select s.student_id, s.student_name, e.subject_name
from Examinations e
join Students s
on e.student_id = s.student_id
group by s.student_id, s.student_name, e.subject_name
*/

select p.student_id, p.student_name, s.subject_name, count(e.student_id) as attended_exams 
from Students p
cross join Subjects s
left join Examinations e
on p.student_id = e.student_id and s.subject_name = e.subject_name
group by p.student_id, p.student_name, s.subject_name
order by p.student_id, s.subject_name
