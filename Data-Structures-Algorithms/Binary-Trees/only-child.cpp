/*
https://binarysearch.com/problems/Only-Child
*/

/*
Given a binary tree root, return the number of nodes that are an only child. 
A node x is an only child if its parent has exactly one child (x).
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};
 
int count_one_child(Tree* root, int count) {
    if(!root)
        return 0;
            
    int left = count_one_child(root->left, count);
    int right = count_one_child(root->right, count);
    if ( root-> left && !root-> right ||
             !root-> left &&  root-> right)
        count++;
    return left + right + count;    
}

int solve(Tree* root) {
    
    int count = count_one_child(root, 0);
    return count;
}