/*
https://binarysearch.com/problems/Merging-Binary-Trees
*/

/*
Given two binary trees node0 and node1, 
return a merge of the two trees where each value is equal to 
the sum of the values of the corresponding nodes of the input trees. 
If only one input tree has a node in a given position, 
the corresponding node in the new tree should match that input node.
*/

#include <bits/stdc++.h> 
using namespace std; 

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

Tree* solve(Tree* node0, Tree* node1) {
    if (node0 || node1) {
        Tree *new_root = new Tree();
        new_root -> val = 0;

        if (node0)
            new_root -> val += node0 -> val;

        if (node1)
            new_root -> val += node1 -> val;

        if (node0 && node1) {
            new_root -> left = solve(node0 -> left, node1 -> left);
            new_root -> right = solve(node0 -> right, node1 -> right);
        }

        else if (node0) {
            new_root -> left = node0 -> left;
            new_root -> right = node0 -> right;
        }

        else if (node1) {
            new_root -> left = node1 -> left;
            new_root -> right = node1 -> right;
        }

        return new_root;
    }
    return NULL;
}