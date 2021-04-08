/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* makeBST(vector<int>& nums, int l, int r) {
        
        if (l > r)
            return NULL;
        
        int mid = l + (r - l)/2;
        
        TreeNode *node = new TreeNode(nums[mid]);
        
        node -> left  = makeBST(nums, l, mid - 1);
        node -> right = makeBST(nums, mid + 1, r);
        
        return node;       
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if (nums.size() == 0)
            return NULL;
        
        TreeNode* root = makeBST(nums, 0, nums.size() - 1);
        
        return root;        
    }
};

/*
5
-10, -3, 0, 5, 9
*/

/*
0 -10 5 null -3 null 9
*/