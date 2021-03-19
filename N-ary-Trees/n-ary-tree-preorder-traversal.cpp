/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/
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
    vector<int> preorder_traversal;
    
    void traversePreorder(Node *root) {
        
        if (root) {
            preorder_traversal.push_back(root -> val);
            
            for (int i = 0; i < root -> children.size(); i++)
                traversePreorder(root -> children[i]);
        }
        
        
    }
    
    vector<int> preorder(Node* root) {        
        traversePreorder(root);
        return preorder_traversal;        
    }
};