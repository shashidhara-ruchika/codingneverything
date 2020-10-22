/*
https://leetcode.com/problems/balanced-binary-tree/
*/

# include <bits/stdc++.h>

using namespace std;

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
    bool ans;
    
    int checkBalance(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        if (!ans)
            return 0;        
        
        int left_height = checkBalance(root -> left);
        int right_height = checkBalance(root -> right);

        if (abs(left_height - right_height) > 1) 
            ans = false;
        
        return max(left_height, right_height) + 1;
        
    }

    bool isBalanced(TreeNode* root) {          
        
        if (root == NULL)
            return true;
        
        ans = true;
        
        int checkbal = checkBalance(root);
        
        return ans;
        
    }
};