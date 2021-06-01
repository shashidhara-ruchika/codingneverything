/*
https://binarysearch.com/problems/Most-Frequent-Subtree-Sum
*/

#include <bits/stdc++.h>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

int node_sum(Tree* root, unordered_map<int, int>& freq) {
    if(root == NULL)
        return 0;
    
    int left_sum = node_sum(root -> left, freq);
    int right_sum = node_sum(root -> right, freq);
    int curr_node_sum = root -> val + left_sum + right_sum;
    if (freq.find(curr_node_sum) != freq.end()) {
        freq[curr_node_sum]++;
    }
    else {
        freq[curr_node_sum] = 1;
    } 
    return curr_node_sum;
}

int solve(Tree* root) {
    unordered_map<int, int> freq;
    int tree_sum = node_sum(root, freq);
    int max_count = 0;
    int max_val = 0;
    for(auto it : freq) {
        if(it.second > max_count) {
            max_count = it.second;
            max_val = it.first;
        }
            
    }
    return max_val;
}