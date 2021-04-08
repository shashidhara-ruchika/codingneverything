/*
--------------------------
TABLE: HACKERS
--------------------------
COLUMN          TYPE
--------------------------
HACKER_ID       INTEGER
NAME            STRING
--------------------------

--------------------------
TABLE: CHALLENGES
--------------------------
COLUMN          TYPE
--------------------------
CHALLENGE_ID    INTEGER
HACKER_ID       INTEGER
--------------------------
*/

/*
https://www.hackerrank.com/challenges/challenges/problem

Julia asked her students to create some coding challenges. 
Write a query to print the hacker_id, name, 
and the total number of challenges created by each student. 
Sort your results by the total number of challenges in descending order. 
If more than one student created the same number of challenges, 
then sort the result by hacker_id. 
If more than one student created the same number of challenges 
and the count is less than the maximum number of challenges created, 
then exclude those students from the result.
*/