/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

# include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL)
            return root;
        
        queue<Node*> q;
        
        q.push(root);
        
        while ( !q.empty() ) {
            
            // only curr level elements array size to be poped out 
            int curr_level_size = q.size();
            
            for(int i = 0; i < curr_level_size; i++) {
                
                Node* curr_node = q.front();
                q.pop();
                
                // all nodes in the same level order except the last but one 
                // will point to the curr node present at front of the queue
                // the last node is initially set to NULL (no need to add this step)
                if (i != curr_level_size - 1)
                    curr_node -> next = q.front();
                
                if (curr_node -> left != NULL)
                    q.push(curr_node -> left);
                
                if (curr_node -> right != NULL)
                    q.push(curr_node -> right);
            }
            
        }
        
        return root;
    }
    
};

