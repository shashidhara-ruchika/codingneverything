/*
---------------------------------
TABLE: STUDENTS
---------------------------------
COLUMN              TYPE
---------------------------------
ID                  INTEGER
NAME                STRING
---------------------------------


---------------------------------
TABLE: FRIENDS
---------------------------------
COLUMN              TYPE
---------------------------------
ID                  INTEGER
FRIEND_ID           INTEGER
---------------------------------


---------------------------------
TABLE: PACKAGES
---------------------------------
COLUMN              TYPE
---------------------------------
ID                  INTEGER
SALARY              FLOAT
---------------------------------
*/

/*
Students contains two columns: ID and Name. 
Friends contains two columns: ID and Friend_ID (ID of the ONLY best friend). 
Packages contains two columns: ID and Salary (offered salary in $ thousands per month).
*/

/*
https://www.hackerrank.com/challenges/placements/problem

Write a query to output the names of those students 
whose best friends got offered a higher salary than them. 
Names must be ordered by the salary amount offered to the best friends. 
It is guaranteed that no two students got same salary offer.
*/
SELECT S.NAME
FROM STUDENTS S
     INNER JOIN FRIENDS F ON S.ID = F.ID
     INNER JOIN PACKAGES P ON S.ID = P.ID
     INNER JOIN PACKAGES PF ON F.FRIEND_ID = PF.ID
WHERE PF.SALARY > P.SALARY
ORDER BY PF.SALARY ASC;

SELECT S.NAME
FROM STUDENTS S INNER JOIN (
    SELECT Q1.ID, Q1.FRIEND_SALARY
    FROM PACKAGES P INNER JOIN  (
        SELECT F1.ID, F1.FRIEND_ID, P1.SALARY AS FRIEND_SALARY
        FROM FRIENDS F1 INNER JOIN PACKAGES P1
        ON F1.FRIEND_ID = P1.ID
    ) AS Q1
    ON Q1.ID = P.ID
    WHERE Q1.FRIEND_SALARY > P.SALARY
) AS Q2
ON S.ID = Q2.ID
ORDER BY Q2.FRIEND_SALARY ASC;
