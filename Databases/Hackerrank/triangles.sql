/*
---------------------------
TABLE: TRIANGLES
---------------------------
COLUMN  TYPE
---------------------------
A       INTEGER
B       INTEGER
C       INTEGER
---------------------------
*/

/*
https://www.hackerrank.com/challenges/what-type-of-triangle/problem

Write a query identifying the type of each record in the TRIANGLES table using its three side lengths. 

Output one of the following statements for each record in the table:
Equilateral: It's a triangle with  sides of equal length.
Isosceles: It's a triangle with  sides of equal length.
Scalene: It's a triangle with  sides of differing lengths.
Not A Triangle: The given values of A, B, and C don't form a triangle.
*/

SELECT 
CASE 
    WHEN (T.A < T.B + T.C) AND
         (T.B < T.A + T.C) AND
         (T.C < T.A + T.B)
    THEN
        CASE
            WHEN (T.A = T.B AND T.B = T.C)
            THEN 'Equilateral'

            WHEN (T.A = T.B) OR
                 (T.A = T.C) OR
                 (T.B = T.C)
            THEN 'Isosceles'

            ELSE 'Scalene'
         END
    
    ELSE 'Not A Triangle'
END
FROM TRIANGLES AS T;




