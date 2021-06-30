/*
https://binarysearch.com/problems/Search-in-a-Virtually-Complete-Binary-Tree
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

// Time:  O(logN)
// Space: O(logN)
bool solve(Tree* root, int target) {

    if (!root || target < 1)
        return false;

    deque<int> dq;
    int tar = target;
    
    while(tar != 1) {
        dq.push_front(tar);
        tar = floor(tar/2);
    }

    Tree* tree_ptr = root;

    while(!dq.empty()) {
        
        int val = dq.front();
        dq.pop_front();

        if (val % 2) // odd => move right
        {
            if (tree_ptr -> right)
                tree_ptr = tree_ptr -> right;
            else
                return false;
        }
        else         // even => move left
        {
            if (tree_ptr -> left)
                tree_ptr = tree_ptr -> left;
            else
                return false;
        }
        
    }

    if (tree_ptr -> val == target)
        return true;

    return false;
}

// Time:  O(N)
// Space: O(N)
bool solve2(Tree* root, int target) {
    
    if (!root || target < 1)
        return false;

    if (root -> val == target)
        return true;

    int level = (int)floor(log(target)/log(2));

    queue<Tree*> q;
    q.push(root);

    int curr_level = 0;
    bool is_found = true;

    while(!q.empty()) {
        
        if (curr_level == level) 
            is_found = false;
        
        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            Tree* curr_node = q.front();
            q.pop();

            if (curr_node -> val == target)
                return true;

            if (curr_node -> left)
                q.push(curr_node -> left);

            if (curr_node -> right)
                q.push(curr_node -> right);
        }

        if (!is_found)
            return false;
        
        level++;        
    }
    return false;
}