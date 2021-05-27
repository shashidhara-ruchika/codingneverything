/*
https://binarysearch.com/problems/Binary-Search-Tree-Iterator
*/

# include <bits/stdc++.h>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class BSTIterator {
    public:
    vector<int> inorder_traversal;
    int t_ptr;

    void insert_traversal(Tree *root)
    {
        if (root != NULL)
        {
            insert_traversal(root -> left);
            inorder_traversal.push_back(root -> val);
            insert_traversal(root -> right);
        }
    }

    BSTIterator(Tree* root) {        
        insert_traversal(root);
        t_ptr = 0;
    }

    int next() {
        int next_val = -1;
        if(t_ptr < inorder_traversal.size())
        {
            next_val = inorder_traversal[t_ptr];
        }
        t_ptr++;
        return next_val;
    }

    bool hasnext() {
        if(t_ptr < inorder_traversal.size())
            return true;
        return false;
    }
};

/*
Input
methods = ["constructor", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "next", "hasnext"]
arguments = [[[2, [1, [0, null, null], null], [3, null, null]]], [], [], [], [], [], [], [], [], [], [], [], [], [], []]`

Output
[null, true, true, 0, true, true, true, 1, true, true, true, 2, true, 3, false]
*/