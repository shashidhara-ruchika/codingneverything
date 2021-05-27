/*
---------------------------------
TABLE: HACKERS
---------------------------------
COLUMN              TYPE
---------------------------------
HACKER_ID           INTEGER
NAME                STRING
---------------------------------


---------------------------------
TABLE: DIFFICULTY
---------------------------------
COLUMN              TYPE
---------------------------------
DIFFICULTY_LEVEL    INTEGER
SCORE               INTEGER
---------------------------------


---------------------------------
TABLE: CHALLENGES
---------------------------------
COLUMN              TYPE
---------------------------------
CHALLENGE_ID        INTEGER
HACKER_ID           INTEGER
DIFFICULTY_LEVEL    INTEGER
---------------------------------


---------------------------------
TABLE: SUBMISSION
---------------------------------
COLUMN              TYPE
---------------------------------
SUBMISSION_ID       INTEGER
HACKER_ID           INTEGER
CHALLENGE_ID        INTEGER
SCORE               INTEGER
---------------------------------
*/

/*
https://www.hackerrank.com/challenges/challenges/problem

Write a query to print the hacker_id, name, 
and the total number of challenges created by each student. 
Sort your results by the total number of challenges in descending order. 
If more than one student created the same number of challenges, 
then sort the result by hacker_id. 
If more than one student created the same number of challenges 
and the count is less than the maximum number of challenges created, 
then exclude those students from the result.
*/

SELECT H.HACKER_ID, H.NAME, COUNT(C.CHALLENGE_ID) AS COUNT_CHALLENGES
FROM HACKERS AS H INNER JOIN CHALLENGES AS C
    ON H.HACKER_ID = C.HACKER_ID
GROUP BY H.HACKER_ID, H.NAME
HAVING
COUNT_CHALLENGES IN (   /* Unique COUNT_CHALLENGES */
    SELECT Q1.COUNT_CHALLENGES_1 
    FROM (
        SELECT C1.HACKER_ID, COUNT(C1.CHALLENGE_ID) AS COUNT_CHALLENGES_1
        FROM CHALLENGES AS C1
        GROUP BY C1.HACKER_ID
        ORDER BY COUNT_CHALLENGES_1 DESC
    ) AS Q1
    GROUP BY Q1.COUNT_CHALLENGES_1
    HAVING COUNT(Q1.COUNT_CHALLENGES_1) = 1
)
OR
COUNT_CHALLENGES = (    /* Maximum COUNT_CHALLENGES */
    SELECT COUNT(C2.CHALLENGE_ID) AS COUNT_CHALLENGES_2
    FROM CHALLENGES AS C2
    GROUP BY C2.HACKER_ID
    ORDER BY COUNT_CHALLENGES_2 DESC
    LIMIT 1  
)
ORDER BY COUNT_CHALLENGES DESC, H.HACKER_ID ASC;

/*
https://www.hackerrank.com/challenges/contest-leaderboard/problem

The total score of a hacker is the sum of their maximum scores for all of the challenges. 
Write a query to print the hacker_id, name, and total score of the hackers 
ordered by the descending score. 
If more than one hacker achieved the same total score, 
then sort the result by ascending hacker_id. 
Exclude all hackers with a total score of 0 from your result.
*/

SELECT H.HACKER_ID, H.NAME, SUM(Q1.MAX_SCORE_PER_CHALLENGE) AS TOTAL_SCORE
FROM HACKERS H INNER JOIN (
    SELECT S1.HACKER_ID, MAX(S1.SCORE) AS MAX_SCORE_PER_CHALLENGE
    FROM SUBMISSIONS S1
    GROUP BY S1.CHALLENGE_ID, S1.HACKER_ID
) AS Q1
ON H.HACKER_ID = Q1.HACKER_ID
GROUP BY H.HACKER_ID, H.NAME
HAVING TOTAL_SCORE > 0
ORDER BY TOTAL_SCORE DESC, H.HACKER_ID ASC;

/*
https://www.hackerrank.com/challenges/full-score/problem

Write a query to print the respective hacker_id and 
name of hackers who achieved full scores for more than one challenge. 
Order your output in descending order by 
the total number of challenges in which the hacker earned a full score. 
If more than one hacker received full scores in same number of challenges, 
then sort them by ascending hacker_id.
*/

SELECT H.HACKER_ID, H.NAME
FROM HACKERS H
    INNER JOIN SUBMISSIONS S ON H.HACKER_ID = S.HACKER_ID
    INNER JOIN CHALLENGES C  ON C.CHALLENGE_ID = S.CHALLENGE_ID
    INNER JOIN DIFFICULTY D  ON D.DIFFICULTY_LEVEL = C.DIFFICULTY_LEVEL
WHERE S.SCORE = D.SCORE
GROUP BY H.HACKER_ID, H.NAME
HAVING COUNT(C.CHALLENGE_ID) > 1
ORDER BY COUNT(C.CHALLENGE_ID) DESC, H.HACKER_ID ASC;    


SELECT H.HACKER_ID, H.NAME
FROM SUBMISSIONS S, CHALLENGES C, DIFFICULTY D, HACKERS H
WHERE 
    S.SCORE = D.SCORE AND 
    S.CHALLENGE_ID = C.CHALLENGE_ID AND
    C.DIFFICULTY_LEVEL = D.DIFFICULTY_LEVEL AND
    S.HACKER_ID = H.HACKER_ID
GROUP BY H.HACKER_ID, H.NAME
HAVING COUNT(C.CHALLENGE_ID) > 1
ORDER BY COUNT(C.CHALLENGE_ID) DESC, H.HACKER_ID ASC;

