/*
https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/
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
    void preorderTraversalRec(TreeNode* root, vector<int> &traversal) {
        
        if (root == NULL)
            return;
        
        traversal.push_back(root -> val);
        
        preorderTraversalRec(root -> left, traversal);
        preorderTraversalRec(root -> right, traversal);   
    }
    
    vector<int> preorderTraversalRecursive(TreeNode* root) {
        
        vector<int> traversal;
        preorderTraversalRec(root, traversal);
        return traversal;       
    }
    
    vector<int> preorderTraversalIterative(TreeNode* root) {
        
        vector<int> traversal;
        
        stack<TreeNode*> stk;
        
        if (root)
            stk.push(root);
        
        while ( !stk.empty() ) {
            
            TreeNode* node = stk.top();
            stk.pop();
            
            traversal.push_back(node -> val);
            
            if (node -> right)
                stk.push(node -> right);
            
            if (node -> left)
                stk.push(node -> left);           
                        
        }
        
        return traversal;
    }
};