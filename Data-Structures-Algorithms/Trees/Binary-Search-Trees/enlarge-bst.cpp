/*
https://binarysearch.com/problems/Enlarge-BST
*/

/*
Given a binary search tree root, replace every node's value v by 
its value plus the sum of all other values in the tree that are greater than v.
*/

#include <bits/stdc++.h> 
using namespace std; 

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};
 
class Enlarge {
    private:
        Tree *root;
        vector<Tree*> inorder_nodes;
    public:
        Enlarge(Tree *root);
        void inorder(Tree *root);
        Tree* solve();
};

Enlarge :: Enlarge(Tree *root) {
    this -> root = root;
}

void Enlarge :: inorder(Tree *root) {
    if (root) {
        inorder(root -> left);
        this -> inorder_nodes.push_back(root);
        inorder(root -> right);
    }
    else 
        return;
}

Tree* Enlarge :: solve() {
    this -> inorder(this -> root);
    if (this -> inorder_nodes.size() < 2)
        return root;

    for (int i = this -> inorder_nodes.size() - 2; i >= 0; i--) {
        
        this -> inorder_nodes[i] -> val += this -> inorder_nodes[i + 1] -> val;
    }
    return this -> root;
}

Tree* solve(Tree* root) {
    Enlarge *e = new Enlarge(root);
    return e -> solve();
}