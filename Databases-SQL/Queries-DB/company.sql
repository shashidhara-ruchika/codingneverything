/*
---------------------------------
TABLE: COMPANY 
---------------------------------
COLUMN                  TYPE
---------------------------------
COMPANY_CODE            STRING
FOUNDER                 STRING
---------------------------------


---------------------------------
TABLE: LEAD_MANAGER 
---------------------------------
COLUMN                  TYPE
---------------------------------
LEAD_MANAGER_CODE       STRING
COMPANY_CODE            STRING
---------------------------------


---------------------------------
TABLE: SENIOR_MANAGER 
---------------------------------
COLUMN                  TYPE
---------------------------------
SENIOR_MANAGER_CODE     STRING
LEAD_MANAGER_CODE       STRING
COMPANY_CODE            STRING
---------------------------------


---------------------------------
TABLE: MANAGER 
---------------------------------
COLUMN                  TYPE
---------------------------------
MANAGER_CODE            STRING
SENIOR_MANAGER_CODE     STRING
LEAD_MANAGER_CODE       STRING
COMPANY_CODE            STRING
---------------------------------


---------------------------------
TABLE: EMPLOYEE
---------------------------------
COLUMN                  TYPE
---------------------------------
EMPLOYEE_CODE           STRING
MANAGER_CODE            STRING
SENIOR_MANAGER_CODE     STRING
LEAD_MANAGER_CODE       STRING
COMPANY_CODE            STRING
---------------------------------
*/

/*
https://www.hackerrank.com/challenges/the-company/problem
*/
/* SELECT */
SELECT C.COMPANY_CODE, C.FOUNDER,
(
    SELECT COUNT(DISTINCT LM.LEAD_MANAGER_CODE)
    FROM LEAD_MANAGER AS LM
    WHERE LM.COMPANY_CODE = C.COMPANY_CODE
),
(
    SELECT COUNT(DISTINCT SM.SENIOR_MANAGER_CODE) 
    FROM SENIOR_MANAGER AS SM
    WHERE SM.COMPANY_CODE = C.COMPANY_CODE
),
(
    SELECT COUNT(DISTINCT M.MANAGER_CODE) 
    FROM MANAGER AS M
    WHERE M.COMPANY_CODE = C.COMPANY_CODE
),
(
    SELECT COUNT(DISTINCT E.EMPLOYEE_CODE) 
    FROM EMPLOYEE AS E
    WHERE E.COMPANY_CODE = C.COMPANY_CODE
)
FROM COMPANY AS C
ORDER BY C.COMPANY_CODE;

/* JOIN */
SELECT   C.COMPANY_CODE, C.FOUNDER,
         COUNT(DISTINCT L.LEAD_MANAGER_CODE),
         COUNT(DISTINCT S.SENIOR_MANAGER_CODE),
         COUNT(DISTINCT M.MANAGER_CODE),
         COUNT(DISTINCT E.EMPLOYEE_CODE)
FROM     COMPANY C, LEAD_MANAGER L, SENIOR_MANAGER S, MANAGER M, EMPLOYEE E
WHERE    L.COMPANY_CODE = C.COMPANY_CODE AND
         S.COMPANY_CODE = C.COMPANY_CODE AND
         M.COMPANY_CODE = C.COMPANY_CODE AND
         E.COMPANY_CODE = C.COMPANY_CODE
GROUP BY C.COMPANY_CODE, C.FOUNDER      
ORDER BY C.COMPANY_CODE;