/*
https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> level_order;
        
        if (root == NULL)
            return level_order;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while ( !q.empty() ) {
            
            // curr level elements array
            vector<int> curr_level;
            
            // only curr level elements array size to be poped out 
            int curr_level_size = q.size();
            
            for(int i = 0; i < curr_level_size; i++) {
                
                TreeNode* curr_node = q.front();
                q.pop();
                
                curr_level.push_back(curr_node -> val);
                
                if(curr_node -> left != NULL)
                    q.push(curr_node -> left);
                
                if(curr_node -> right != NULL)
                    q.push(curr_node -> right);
            }
            
            int curr_order_size = level_order.size();
            
            if (curr_order_size % 2)
                reverse(curr_level.begin(), curr_level.end());
                
            level_order.push_back(curr_level);
        }
        
        return level_order;
        
    }
};