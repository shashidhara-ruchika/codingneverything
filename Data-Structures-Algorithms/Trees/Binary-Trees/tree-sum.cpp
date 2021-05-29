/*
https://binarysearch.com/problems/Tree-Sum
https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
*/

# include <bits/stdc++.h>

using namespace std;
class Tree {
     public:
        int val;
        Tree *left;
        Tree *right;
};

int sum_inorder(Tree* root) {
    int sum = 0;
    if (root == NULL)
        return 0;
    if (root -> left)
        sum += sum_inorder(root -> left);
    if (root -> right)
        sum += sum_inorder(root -> right);
    return sum += root -> val;
}

int solve(Tree* root) {
    return sum_inorder(root);
}

/*
Input
root = [1, [2, null, null], [3, [5, null, null], null]]

Output
11

Explanation
11 = 1 + 2 + 3 + 5
*/