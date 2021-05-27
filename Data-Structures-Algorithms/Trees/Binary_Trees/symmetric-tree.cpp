/*
https://leetcode.com/problems/symmetric-tree/
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
    bool isMirror(TreeNode* tl, TreeNode* tr) {
        
        if (tl == NULL && tr == NULL)
            return true;
        
        if (tl == NULL || tr == NULL)
            return false;
        
        return (tl -> val == tr -> val) 
        && isMirror(tl -> left, tr -> right) && isMirror(tl -> right, tr -> left) ;
        
    }

    bool isSymmetric_recursive(TreeNode* root) {
        
        if (root == NULL)
            return true;
        
        return isMirror(root -> left, root -> right);
        
    }

    bool isSymmetric_iterative(TreeNode* root) {
        
        if (root == NULL)
            return true;
        
        queue<TreeNode*> ql;
        queue<TreeNode*> qr;
        
        TreeNode *l, *r;
        
        ql.push(root -> left);
        qr.push(root -> right);
        
        while ( !ql.empty() ) {
            
            l = ql.front();     ql.pop();           
            r = qr.front();     qr.pop();
            
            if (l == NULL && r == NULL)
                continue;
            
            if (l == NULL || r == NULL)
                return false;
            
            if (l -> val != r -> val)
                return false;
            
            ql.push(l -> left);     qr.push(r -> right);
            ql.push(l -> right);    qr.push(r -> left);
        }
            
        return true;        
    }
};

int main() {

    /*
    6
    1 2 2 3 4 4 3
    6
    1 2 2 null 3 null 3
    */

    /*
    1
    0
    */


    return 0;
}