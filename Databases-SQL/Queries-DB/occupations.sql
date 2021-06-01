/*
---------------------------
TABLE: OCCUPATIONS
---------------------------
COLUMN      TYPE
---------------------------
NAME        STRING
OCCUPATION  STRING
---------------------------
*/

/*
https://www.hackerrank.com/challenges/the-pads/problem

Generate the following two result sets:

Query an alphabetically ordered list of all names in OCCUPATIONS, 
immediately followed by the first letter of each profession as a parenthetical (i.e.: enclosed in parentheses). 
For example: AnActorName(A), ADoctorName(D), AProfessorName(P), and ASingerName(S).

Query the number of ocurrences of each occupation in OCCUPATIONS. 
Sort the occurrences in ascending order, and output them in the following format:
    There are a total of [occupation_count] [occupation]s.
    where [occupation_count] is the number of occurrences of an occupation in OCCUPATIONS 
    and [occupation] is the lowercase occupation name. 
    If more than one Occupation has the same [occupation_count], they should be ordered alphabetically.

Note: There will be at least two entries in the table for each type of occupation.
*/

SELECT 
CONCAT
(
    O.NAME,     
    '(',    
    SUBSTR(O.OCCUPATION,1,1),
    ')'         
)
FROM OCCUPATIONS AS O
ORDER BY O.NAME ASC;

SELECT
CONCAT
(
    'There are a total of ',
    COUNT(O.OCCUPATION),
    ' ',
    LOWER(O.OCCUPATION),
    's.'
)
FROM OCCUPATIONS AS O
GROUP BY O.OCCUPATION
ORDER BY COUNT(O.OCCUPATION) ASC;


/*
https://www.hackerrank.com/challenges/occupations/problem

Pivot the Occupation column in OCCUPATIONS 
so that each Name is sorted alphabetically 
and displayed underneath its corresponding Occupation. 
The output column headers should be 
Doctor, Professor, Singer, and Actor, respectively.
*/