/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    // takes 332 ms, very slow
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left_minDepth = minDepth(root -> left);
        int right_minDepth = minDepth(root -> right);
        
        if (left_minDepth == 0 or right_minDepth == 0)
            return max(left_minDepth, right_minDepth) + 1;
        
        return min(left_minDepth, right_minDepth) + 1;
    }
};
