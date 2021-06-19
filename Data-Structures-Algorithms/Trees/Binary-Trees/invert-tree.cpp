/*
https://binarysearch.com/problems/Invert-Tree
*/

#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

Tree* solve(Tree* root) {

    if (root) {

        Tree* left = NULL;
        Tree* right = NULL;

        left = solve(root -> left);

        right = solve(root -> right);
    
        root -> left = right;
        root -> right = left;
    }

    return root;
}