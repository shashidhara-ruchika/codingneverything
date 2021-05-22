/*
https://binarysearch.com/problems/Inorder-Successor
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class bst {
    private:
        vector<int> inorder;
    public:
        void insert_inorder(Tree * root);
        int get_inorder_successor(int t);
};

void bst :: insert_inorder(Tree *root) {
    
    if (!root)
        return;

    if (root -> left)
        insert_inorder(root -> left);

    this -> inorder.push_back(root -> val);

    if (root -> right)
        insert_inorder(root -> right);
}

int bst :: get_inorder_successor(int t) {
    auto it = find(this -> inorder.begin(), this -> inorder.end(), t);
    return *(it + 1);
}

int print_inorder_successor(Tree* root, int t) {
    bst *bstp = new bst();
    bstp -> insert_inorder(root);
    return bstp -> get_inorder_successor(t);
}