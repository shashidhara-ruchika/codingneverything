/*
https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/930/
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
    void postorderTraversalRec(TreeNode* root, vector<int> &traversal) {
        
        if (root == NULL)
            return;
        
        postorderTraversalRec(root -> left, traversal);       
        
        postorderTraversalRec(root -> right, traversal);  
        
        traversal.push_back(root -> val);   
    }
    
    vector<int> postorderTraversalRecursive(TreeNode* root) {
        
        vector<int> traversal;
        postorderTraversalRec(root, traversal);
        return traversal;       
    }    
    
    vector<int> postorderTraversalIterative(TreeNode* root) {
        
        vector<int> traversal;
        
        stack<TreeNode*> s;
        
        while(true) { 
            
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            } 
            
            if (s.empty()) 
                break;
            
            root = s.top();
            
            if (root->right != nullptr) 
                root = root->right;
            
            else {
            
                traversal.push_back(root->val);
                
                s.pop();
                
                while (!s.empty() && s.top()->right == root) {
                    root = s.top();
                    traversal.push_back(root->val);
                    s.pop();
                }
                root = (!s.empty()) ? s.top() -> right : nullptr;
            }
            
        }
        
        return traversal;
    }
};