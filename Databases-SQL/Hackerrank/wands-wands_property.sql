/*
--------------------------------
TABLE: WANDS
--------------------------------
COLUMN              TYPE
--------------------------------
ID                  INTEGER
CODE                INTEGER
COINS_NEEDED        INTEGER
POWER               INTEGER
--------------------------------


--------------------------------
TABLE: WANDS_PROPERTY
--------------------------------
COLUMN              TYPE
--------------------------------
CODE                INTEGER
AGE                 INTEGER
IS_EVIL             INTEGER
--------------------------------
*/

/*
https://www.hackerrank.com/challenges/harry-potter-and-wands/problem

Harry Potter and his friends are at Ollivander's with Ron, 
finally replacing Charlie's old broken wand.
Hermione decides the best way to choose is by determining 
the minimum number of gold galleons needed to buy each non-evil wand of high power and age. 
Write a query to print the id, age, coins_needed, and 
power of the wands that Ron's interested in, sorted in order of descending power. 
If more than one wand has same power, sort the result in order of descending age.
*/

SELECT W.ID, WP.AGE, W.COINS_NEEDED, W.POWER
FROM WANDS W INNER JOIN WANDS_PROPERTY WP
    ON W.CODE = WP.CODE
WHERE (WP.AGE, W.POWER, W.COINS_NEEDED) IN (
    SELECT WP1.AGE, W1.POWER, MIN(W1.COINS_NEEDED)
    FROM WANDS W1 INNER JOIN WANDS_PROPERTY WP1
        ON W1.CODE = WP1.CODE
    WHERE WP1.IS_EVIL = 0
    GROUP BY W1.POWER, WP1.AGE
)
ORDER BY W.POWER DESC, WP.AGE DESC;

