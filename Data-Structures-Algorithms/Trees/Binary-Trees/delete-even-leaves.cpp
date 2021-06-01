/*
https://binarysearch.com/problems/Delete-Even-Leaves
*/

#include <bits/stdc++.h>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

bool del_even_leaves(Tree* root) {
    if(!root)
        return true;
    
    bool check_left = del_even_leaves(root -> left);
    bool check_right = del_even_leaves(root -> right);

    if(check_left && root -> left) {
        root -> left = NULL;
        delete root -> left;
    }
    if(check_right && root -> right) {
        root -> right = NULL;
        delete root -> right;
    }

    if(root -> val % 2 == 0 && check_left && check_right)
        return true;
    return false;

}

Tree* solve(Tree* root) {
    bool check_deleted = del_even_leaves(root);
    if(check_deleted)
        return NULL;
    return root;
}