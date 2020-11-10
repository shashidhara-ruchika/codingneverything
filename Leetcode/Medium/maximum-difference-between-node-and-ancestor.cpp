/*
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    int getADiff(TreeNode* node, int currMin, int currMax) {
        
        //cout << currMin << " " << currMax << endl;
        
        if (node == NULL)
            return currMax - currMin;        
        
        currMax = max(currMax, node -> val);
        currMin = min(currMin, node -> val);
        
        int leftMax  = getADiff(node -> left,  currMin, currMax);
        int rightMax = getADiff(node -> right, currMin, currMax);
        
        return max(leftMax, rightMax);         
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        return getADiff(root, root -> val, root -> val);
    }
};