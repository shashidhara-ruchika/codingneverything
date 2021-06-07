/*
https://binarysearch.com/problems/Sum-of-Nodes-with-Even-Grandparent-Values
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

void traverse_node(Tree* root, int *s) {
    if(!root) 
        return;

    if(root -> val % 2 == 0) {
        if(root -> left && root -> left -> left)
            *s += root -> left -> left -> val;
        
        if(root -> left && root -> left -> right)
            *s += root -> left -> right -> val;

        if(root -> right && root -> right -> left)
            *s += root -> right -> left -> val;


        if(root -> right && root -> right -> right)
            *s += root -> right -> right -> val;
    }

    traverse_node(root -> left, s);
    traverse_node(root -> right, s);

}

int solve(Tree* root) {
    int s = 0;
    traverse_node(root, &s);
    return s;
}