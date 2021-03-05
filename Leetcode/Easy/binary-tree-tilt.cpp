/*
https://leetcode.com/problems/binary-tree-top/
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
private:
    int totalTilt = 0;
public:
    int findSum(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        int leftSum = findSum(root -> left);
        int rightSum = findSum(root -> right);
        
        totalTilt += abs(leftSum - rightSum);
        
        return root -> val + leftSum + rightSum;
    }
    
    int findTilt(TreeNode* root) {
        
        totalTilt = 0;
        
        int rootSum = findSum(root);
        
        return totalTilt;        
    }
};