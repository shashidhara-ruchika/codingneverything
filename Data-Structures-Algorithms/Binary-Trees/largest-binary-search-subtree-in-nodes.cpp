/*
https://binarysearch.com/problems/Largest-Binary-Search-Subtree-in-Nodes
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};


class new_btree {
    private:
        Tree* btree;
        map<Tree*, pair<int, bool>> marker;
        void mark_tree(Tree *root);
        int max_count = -1;
        Tree* max_node;

    public:
        new_btree(Tree *root);
        Tree* get_max_node();
};

new_btree :: new_btree(Tree *root) {
    this -> btree = root;
    mark_tree(this -> btree);
}

void new_btree :: mark_tree(Tree *root) {
    
    if (!root)
        return;
    
    int left_val = -1;
    int right_val = -1;
    int lcount = 0;
    int rcount = 0;
    bool lcheck = true;
    bool rcheck = true;
    bool check = false;

    if (root -> left) {
        mark_tree(root -> left);
        lcount = this -> marker[root -> left].first;
        lcheck = this -> marker[root -> left].second;
        left_val = root -> left -> val;
    }

    if (root -> right) {
        mark_tree(root -> right);
        rcount = this -> marker[root -> right].first;
        rcheck = this -> marker[root -> right].second;
        right_val = root -> right -> val;
    }

    int count = lcount + rcount + 1;

    if ((left_val == -1 || left_val <= root -> val) && 
        (right_val == -1 || right_val >= root -> val)) {
        
        check = lcheck && rcheck;
        if (check && count > max_count) {
            max_count = count;
            this -> max_node = root;
        }

    }

    this -> marker[root] = {count, check};
}

Tree* new_btree :: get_max_node() {
    return this -> max_node;
}

Tree* solve(Tree* root) {
    new_btree *nbtp = new new_btree(root);
    return nbtp -> get_max_node();
}