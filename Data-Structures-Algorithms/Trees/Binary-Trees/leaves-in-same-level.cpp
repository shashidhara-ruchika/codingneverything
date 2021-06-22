/*
https://binarysearch.com/problems/Leaves-in-Same-Level
*/

#include <bits/stdc++.h>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

void height(Tree* root, set<int>& leaves, int level) {
    if (root) {
        if (!root -> left && !root -> right) {
            leaves.insert(level);
        }
        else {
            height(root -> left, leaves, level + 1);
            height(root -> right, leaves, level + 1);
        }        
    }
}
bool solve(Tree* root) {
    set<int> leaves;
    height(root, leaves, 0);
    if (leaves.size() < 2)
        return true;
    else
        return false;
}

// [3, [4, null, [2, null, null]], [1, [0, null, null], null]]
// [1, [2, null, null], [3, null, [4, null, null]]]