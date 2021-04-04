/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

# include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       
        if (root == NULL)
            return {};
        
        vector<vector<int>> level_order;      
        
        queue<Node*> q;
        
        q.push(root);
        
        while ( !q.empty() ) {
            
            int curr_level_size = q.size();
            
            vector<int> curr_level;           
            
            for(int i = 0; i < curr_level_size; i++) {
                
                Node* curr_node = q.front();
                q.pop();
                
                curr_level.push_back(curr_node -> val);
                
                //for (auto curr_node_child: curr_node -> children)
                    //q.push(curr_node_child);
                
                for (int i = 0; i < curr_node -> children.size(); i++)
                    q.push(curr_node -> children[i]);
                
            }
            
            level_order.push_back(curr_level);
        }
        
        return level_order;
    }
};