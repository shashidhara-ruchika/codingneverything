/*
https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int> inorderTraversal;
    
    void inorder(TreeNode* root) {
        
        if ( root ) {            
            inorder(root -> left);
            this -> inorderTraversal.push_back(root -> val);
            inorder(root -> right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        
        if ( ! root )
            return true;
        
        inorder(root);
        
        for (int i = 0; i < inorderTraversal.size() - 1; i++) {
            if ( ! (inorderTraversal[i] < inorderTraversal[i + 1]) )
                return false;
        }
        
        return true;
    }
};

int main() {
    return 0;
}