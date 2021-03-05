/*
https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/929/
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
    void inorderTraversalRec(TreeNode* root, vector<int> &traversal) {
        
        if (root == NULL)
            return;
        
        inorderTraversalRec(root -> left, traversal);
        
        traversal.push_back(root -> val);        
        
        inorderTraversalRec(root -> right, traversal);   
    }
    
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        
        vector<int> traversal;
        inorderTraversalRec(root, traversal);
        return traversal;       
    }    
    
    vector<int> inorderTraversalIterative(TreeNode* root) {
        
        vector<int> traversal;
        
        stack<TreeNode*> st;
        
        while (1) {
            
            while(root) {
                st.push(root);
                root = root->left;
            }
            
            if(st.empty()) 
                break;
            
            TreeNode *node = st.top();
            st.pop();
            
            traversal.push_back(node -> val);
            
            if(node -> right)
                root= node -> right;
        }
        
        return traversal;
    }
};