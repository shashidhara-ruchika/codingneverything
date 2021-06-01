/*
-------------------------------------------
TABLE: CONTESTS
-------------------------------------------
COLUMN                          TYPE
-------------------------------------------
CONTEST_ID                      INTEGER
HACKER_ID                       INTEGER
NAME                            STRING
-------------------------------------------


-------------------------------------------
TABLE: COLLEGES
-------------------------------------------
COLUMN                          TYPE
-------------------------------------------
COLLEGE_ID                      INTEGER
CONTEST_ID                      INTEGER
-------------------------------------------


-------------------------------------------
TABLE: CHALLENGES
-------------------------------------------
COLUMN                          TYPE
-------------------------------------------
CHALLENGE_ID                    INTEGER
COLLEGE_ID                      INTEGER
-------------------------------------------


-------------------------------------------
TABLE: VIEW_STATS
-------------------------------------------
COLUMN                          TYPE
-------------------------------------------
CHALLENGE_ID                    INTEGER
TOTAL_VIEWS                     INTEGER
TOTAL_UNIQUE_VIEWS              INTEGER
-------------------------------------------


-------------------------------------------
TABLE: SUBMISSION_STATS
-------------------------------------------
COLUMN                          TYPE
-------------------------------------------
CHALLENGE_ID                    INTEGER
TOTAL_SUBMISSIONS               INTEGER
TOTAL_ACCEPTED_SUBMISSIONS      INTEGER
-------------------------------------------
*/

/*
https://www.hackerrank.com/challenges/interviews/problem?
*/

SELECT 
    CN.CONTEST_ID, CN.HACKER_ID, CN.NAME,
    SUM(TOTAL_SUBMISSIONS) AS TS, SUM(TOTAL_ACCEPTED_SUBMISSIONS) AS TAS,
    SUM(TOTAL_VIEWS) AS TV, SUM(TOTAL_UNIQUE_VIEWS) AS TUV
FROM  
    CONTESTS AS CN
    INNER JOIN COLLEGES AS CL ON CN.CONTEST_ID = CL.CONTEST_ID
    INNER JOIN CHALLENGES AS CH ON CL.COLLEGE_ID = CH.COLLEGE_ID
    LEFT JOIN (
        SELECT 
            CHALLENGE_ID, 
            SUM(TOTAL_VIEWS) AS TOTAL_VIEWS, 
            SUM(TOTAL_UNIQUE_VIEWS) AS TOTAL_UNIQUE_VIEWS
        FROM VIEW_STATS
        GROUP BY CHALLENGE_ID
    ) AS VS ON CH.CHALLENGE_ID = VS.CHALLENGE_ID
    LEFT JOIN (
        SELECT 
            CHALLENGE_ID, 
            SUM(TOTAL_SUBMISSIONS) AS TOTAL_SUBMISSIONS, 
            SUM(TOTAL_ACCEPTED_SUBMISSIONS) AS TOTAL_ACCEPTED_SUBMISSIONS
        FROM SUBMISSION_STATS
        GROUP BY CHALLENGE_ID
    ) AS SS ON CH.CHALLENGE_ID = SS.CHALLENGE_ID
GROUP BY CN.CONTEST_ID, CN.HACKER_ID, CN.NAME
HAVING TS != 0 OR TAS != 0 OR TV != 0 OR TUV != 0
ORDER BY CN.CONTEST_ID ASC;
        
