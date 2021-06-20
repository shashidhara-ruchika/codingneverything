/*
https://binarysearch.com/problems/Sibling-Tree-Value
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int sibling_tree_value(Tree* root, int k) {
    queue<Tree*> q;
    vector<int> level_order;
    q.push(root);
    while(!q.empty()) {
        Tree* curr = q.front();
        q.pop();
        level_order.push_back(curr -> val);
        if (curr -> left && curr -> right) {
            q.push(curr -> left);
            q.push(curr -> right);
        }            
    }
    for(int i = 1; i < level_order.size(); i++) {
        if (level_order[i] == k) {
            if (i % 2)
                return level_order[i + 1];
            else 
                return level_order[i - 1];
        }
            
    }
    return 0;
}