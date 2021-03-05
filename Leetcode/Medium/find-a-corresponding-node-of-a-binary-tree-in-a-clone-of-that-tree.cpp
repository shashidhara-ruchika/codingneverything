/*
https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
*/

# include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *tar;
    TreeNode *clonedtar = NULL;
    
    void inorder(TreeNode *original, TreeNode *cloned) {
        
        if (original != NULL) {
            
            inorder(original -> left, cloned -> left);
            if (original == tar) {
                clonedtar = cloned;
                return;
            }
                
            
            inorder(original -> right, cloned -> right);
            if (original == tar) {
                clonedtar = cloned;
                return;
            }
                        
            
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        tar = target;
        inorder(original, cloned);
        return clonedtar;
    }
};

int main() {
    return 0;
}