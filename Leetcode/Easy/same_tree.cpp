/*
https://leetcode.com/problems/same-tree/
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
    int isSameNode(TreeNode *p, TreeNode *q) {
        
        // if both p & q are NULL
        if (p == NULL && q == NULL)
            return 0;
        
        // If only one of p or q is NULL
        if (p == NULL || q == NULL)
            return -1;
        
        if (p -> val != q -> val)
            return -2;
        
        return 1;        
    }    

public:    

    bool isSameTree_recursion(TreeNode* p, TreeNode* q) {
        
        // both p & q are null
        if (p == NULL && q == NULL)
            return true;
        
        // if only one of p or is null
        if (p == NULL || q == NULL)
            return false;
        
        if (p -> val != q -> val)
            return false;
        
        return isSameTree_recursion(p -> left, q -> left) && isSameTree_recursion(p -> right, q -> right);
        
    }

    bool isSameTree_iterative(TreeNode* p, TreeNode* q) {
        
        int check = isSameNode(p, q), checkl, checkr;
        
        if (check == 0)
            return true;
        
        if (check < 0)
            return false;
        
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        
        pq.push(p);
        qq.push(q);
        
        TreeNode *p_new, *q_new;
        
        while ( !pq.empty() ) {
            
            p_new = pq.front();
            q_new = qq.front();            
            pq.pop();
            qq.pop();
            check = isSameNode(p_new, q_new);
            
            if (check < 0)
                return false;
            
            if (check == 1) {
                
                checkl = isSameNode(p_new -> left, q_new -> left);
                if (checkl < 0)
                    return false;
                if (checkl == 1) {
                    pq.push(p_new -> left);
                    qq.push(q_new -> left);
                }
                
                checkr = isSameNode(p_new -> right, q_new -> right);
                if (checkr < 0)
                    return false;
                if (checkr == 1) {
                    pq.push(p_new -> right);
                    qq.push(q_new -> right);
                }
                
            }
            
        }
        
        return true;
    }
};

int main() {

    /*
    3 3
    1 2 3
    1 2 3
    2 3
    1 2
    1 null 2
    */

    /*
    1
    0
    */
    
    
    return 0;
}