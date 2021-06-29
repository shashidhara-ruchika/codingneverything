/*
https://binarysearch.com/problems/Level-Order-Binary-Tree-to-Linked-List
*/

#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class LLNode {
    public:
        int val;
        LLNode *next;
};

LLNode* level_order_binary_tree_to_linked_list(Tree* root) {
    LLNode* head = new LLNode();
    head -> val = 0;
    head -> next = NULL;
    LLNode* curr_list = head;

    queue<Tree*> q;
    q.push(root);

    while(!q.empty()) {
        Tree* curr_node = q.front();
        q.pop();
        LLNode* new_node = new LLNode();
        new_node -> val = curr_node -> val;
        new_node -> next = NULL;
        curr_list -> next = new_node;
        curr_list = curr_list -> next;

        if (curr_node -> left)
            q.push(curr_node -> left);

        if (curr_node -> right)
            q.push(curr_node -> right);
    }

    return head -> next;
}



