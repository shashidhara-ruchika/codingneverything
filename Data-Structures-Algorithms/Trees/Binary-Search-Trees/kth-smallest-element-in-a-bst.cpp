/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

# include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorder_traversal;
    
    void traverse_inorder(TreeNode *root) {
        
        if (root) {
            traverse_inorder(root -> left);
            inorder_traversal.push_back(root -> val);
            traverse_inorder(root -> right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        traverse_inorder(root);
        return inorder_traversal[k - 1];
    }
};