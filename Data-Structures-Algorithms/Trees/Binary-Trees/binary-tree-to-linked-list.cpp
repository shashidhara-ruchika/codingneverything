/*
https://binarysearch.com/problems/Binary-Tree-to-Linked-List
*/

# include <bits/stdc++.h>

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

class convert {
    private:
        LLNode *list_head;
        LLNode *list_end;
        Tree* root;
    public:
        convert(Tree *root);
        void solve();
        void inorder(Tree *root);
        void insert_list(int val);
        LLNode* get_list();
};

convert :: convert(Tree *root) {
    this -> root = root;
    LLNode *new_node = new LLNode();
    new_node -> val = -1;
    new_node -> next = NULL;
    this -> list_head = new_node;
    this -> list_end = new_node;
}

void convert ::solve() {
    inorder(this -> root);
}

void convert :: inorder(Tree *root) {
    if (root) {
        inorder(root -> left);
        this -> insert_list(root -> val);
        //cout << root -> val << " ";
        inorder(root -> right);
    }
    else {
        return;
    }
}

LLNode* convert :: get_list() {
    return this -> list_head -> next;
}

void convert :: insert_list(int val) {
    LLNode *new_node = new LLNode();
    new_node -> val = val;
    new_node -> next = NULL;
    this -> list_end -> next = new_node;
    this -> list_end = this -> list_end -> next;
}

LLNode* solve(Tree* root) {
    convert *c = new convert(root);
    c -> solve();
    LLNode *list = c -> get_list(); 
    return list;
}
