/*
--------------------------
TABLE: FUNCTIONS
--------------------------
COLUMN  TYPE
--------------------------
x       INTEGER
Y       INTEGER
--------------------------
*/

/*
https://www.hackerrank.com/challenges/symmetric-pairs/problem

You are given a table, Functions, containing two columns: X and Y.

Two pairs (X1, Y1) and (X2, Y2) are said to be symmetric pairs 
if X1 = Y2 and X2 = Y1.

Write a query to output all such symmetric pairs 
in ascending order by the value of X. 
List the rows such that X1 ≤ Y1.
*/

SELECT F1.X, F1.Y 
FROM FUNCTIONS F1 INNER JOIN FUNCTIONS F2
ON F1.X = F2.Y AND F1.Y = F2.X
GROUP BY F1.X, F1.Y
HAVING COUNT(F1.X) > 1 OR F1.X < F1.Y
ORDER BY F1.X;

/*
The key is the HAVING line, with two conditions.

The first condition - COUNT(F1.X)
makes sure pairs with the same X and Y values 
don't get to count themselves as their symmetric pair. 
(e.g. if 10 10 appears one time it's not counted as a symmetric pair, 
but as 13 13 appears twice, that is a symmetric pair)

The second condition - F1.X < F1.Y
 ensures that only one of a pair is displayed. 
 (e.g. if 3 24 and 24 3 form a symmetric pair, 
 it will only display 3 24, not 24 3 as well.)
*/