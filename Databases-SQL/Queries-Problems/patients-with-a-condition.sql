/*

https://leetcode.com/problems/patients-with-a-condition/

Table: Patients

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key (column with unique values) for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.
 

Write a solution to find the patient_id, patient_name, and conditions of the patients 
who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.
*/


# Write your MySQL query statement below
select * from  Patients where conditions REGEXP '(^|[[:space:]])DIAB1'

SELECT *
FROM Patients
WHERE conditions REGEXP '\\bDIAB1';

