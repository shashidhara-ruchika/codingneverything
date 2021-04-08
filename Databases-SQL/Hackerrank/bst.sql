/*
---------------------------
TABLE: BST
---------------------------
COLUMN  TYPE
---------------------------
N       INTEGER
P       INTEGER
---------------------------
*/

/*
https://www.hackerrank.com/challenges/binary-search-tree-1/problem

You are given a table, BST, containing two columns: N and P, 
where N represents the value of a node in Binary Tree, and P is the parent of N.

Write a query to find the node type of Binary Tree ordered by the value of the node. 
Output one of the following for each node:

Root: If node is root node.
Leaf: If node is leaf node.
Inner: If node is neither root nor leaf node.
*/

SELECT 
CASE
    WHEN (BST.P IS NULL)
    THEN CONCAT(BST.N, ' Root')
    
    WHEN BST.N IN 
    (
        SELECT DISTINCT BST.P
        FROM BST
    )
    THEN CONCAT(BST.N, ' Inner')
    
    ELSE CONCAT(BST.N, ' Leaf')
END
FROM BST
ORDER BY BST.N ASC;

SELECT BST.N,
    IF 
    (
        BST.P IS NULL,
        'Root',
        IF 
        (
            BST.N IN 
            (
                SELECT DISTINCT BST.P
                FROM BST
            ),
            'Inner',
            'Leaf'
        )
    )    
FROM BST 
ORDER BY BST.N ASC;
