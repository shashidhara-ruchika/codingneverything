/*
-----------------------
TABLE: STUDENTS
-----------------------
COLUMN      TYPE
-----------------------
ID          INTEGER
NAME        STRING
MARKS       NUMBER
-----------------------


-----------------------
TABLE: GRADES
-----------------------
COLUMN      TYPE
-----------------------
GRADE       NUMBER
MIN_MARK    NUMBER
MAX_MARK    NUMBER
-----------------------
*/

/*
https://www.hackerrank.com/challenges/more-than-75-marks/problem

Query the Name of any student in STUDENTS who scored higher than  Marks.
Order your output by the last three characters of each name.
If two or more students both have names ending in the same last three characters
(i.e.: Bobby, Robby, etc.), secondary sort them by ascending ID.
*/

SELECT STUDENTS.Name
FROM STUDENTS
WHERE STUDENTS.Marks > 75
ORDER BY SUBSTRING(STUDENTS.Name, -3), ID ASC;

/*
https://www.hackerrank.com/challenges/the-report/problem

You are given two tables: Students and Grades.
Ketty gives Eve a task to generate a report containing three columns: Name, Grade and Mark. 

Ketty doesn't want the NAMES of those students who received a grade lower than 8. 
The report must be in descending order by grade -- i.e. higher grades are entered first. 
If there is more than one student with the same grade (8-10) assigned to them, 
order those particular students by their name alphabetically. 
Finally, if the grade is lower than 8, use "NULL" as their name 
and list them by their grades in descending order. 
If there is more than one student with the same grade (1-7) assigned to them, 
order those particular students by their marks in ascending order.

Write a query to help Eve.
*/

SELECT S.NAME, G.GRADE, S.MARKS
FROM STUDENTS AS S LEFT JOIN GRADES AS G
ON S.MARKS >= MIN_MARK AND S.MARKS <= MAX_MARK
WHERE G.GRADE >= 8
ORDER BY G.GRADE DESC, S.NAME ASC;

SELECT NULL, G.GRADE, S.MARKS
FROM STUDENTS AS S LEFT JOIN GRADES AS G
ON S.MARKS >= MIN_MARK AND S.MARKS <= MAX_MARK
WHERE G.GRADE < 8
ORDER BY G.GRADE DESC, S.MARKS ASC;

