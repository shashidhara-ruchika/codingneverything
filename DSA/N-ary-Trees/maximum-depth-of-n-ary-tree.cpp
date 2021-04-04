/*
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
    int maxDepth_recursive(Node* root) {
        
        if (root == NULL)
            return 0;
        
        int curr_max_depth = 0;
        
        for (int i = 0; i < root -> children.size(); i++) {
            
            int curr_depth = maxDepth_recursive(root -> children[i]);
            curr_max_depth = max(curr_depth, curr_max_depth);
        }
        
        return curr_max_depth + 1;
    }

    int maxDepth_iterative(Node* root) {
        
        if (!root)
            return 0;
        
        int depth = 0, q_size;
        
        queue<Node*> q;
        q.push(root);
        
        Node* node;
        
        while ( !q.empty() ) {
            
            q_size = q.size();
            
            for(int i = 0; i < q_size; i++) {
                
                node = q.front();
                q.pop();
                
                for (int i = 0; i < node -> children.size(); i++)
                    q.push(node -> children[i]);
                
            }
            ++depth;
        }
        return depth;
    }
};