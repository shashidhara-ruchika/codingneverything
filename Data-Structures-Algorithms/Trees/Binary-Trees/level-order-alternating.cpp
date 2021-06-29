/*
https://binarysearch.com/problems/Level-Order-Alternating
*/

#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

vector<int> level_order_alternating(Tree* root) {
    vector<int> alternating_level_order;

    queue<Tree*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()) {
        
        deque<int> dq;

        int curr_level_size = q.size();

        for (int i = 0; i < curr_level_size; i++) {

            Tree* curr_node = q.front();
            q.pop();

            dq.push_back(curr_node -> val);

            if (curr_node -> left)
                q.push(curr_node -> left);
            
            if (curr_node -> right)
                q.push(curr_node -> right);
        }

        if (level % 2) {
            while(!dq.empty()) {
                alternating_level_order.push_back(dq.back());
                dq.pop_back();
            }
        }

        else {
            while(!dq.empty()) {
                alternating_level_order.push_back(dq.front());
                dq.pop_front();
            }
        }

        level++;
    }

    return alternating_level_order;
}
//[3, [0, null, [2, [1, null, null], null]], [4, null, null]]
//[3, [0, [5, null, null], [2, null, null]], null]
//[0, [4, null, [1, null, null]], [2, [3, null, null], null]]
