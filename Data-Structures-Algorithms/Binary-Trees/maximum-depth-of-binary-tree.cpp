/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

    int maxDepth_recursive(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        return max( maxDepth_recursive(root -> left),  maxDepth_recursive(root -> right) ) + 1;      
    }

    int maxDepth_iterative(TreeNode* root) {
        
        if (!root)
            return 0;
        
        int depth = 0, q_size;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* node;
        
        while ( !q.empty() ) {
            
            q_size = q.size();
            
            for(int i = 0; i < q_size; i++) {
                
                node = q.front();
                q.pop();
                
                if (node -> left)
                    q.push(node -> left);
                
                if (node -> right)
                    q.push(node -> right);
            }
            ++depth;
        }
        return depth;
    }

    void solve_recursive() {

        int n; 
        cin >> n;
        string s;

        if (n == 0) {
            cin >> s;
            cout << maxDepth_recursive(NULL) << endl;
            return;
        }
        
        cin >> s;
        TreeNode t = TreeNode(stoi(s));

        if (n == 1) {
            cout << maxDepth_recursive(&t) << endl;
            return;
        }         

    }
};


int main() {

    /*
    7
    3 9 20 null null 15 7
    */

    /*
    3
    */

    Solution soln_rec;
    soln_rec.solve_recursive();

    return 0;
}
