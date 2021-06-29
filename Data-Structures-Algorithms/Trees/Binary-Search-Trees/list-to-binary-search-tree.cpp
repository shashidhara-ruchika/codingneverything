/*
https://binarysearch.com/problems/List-to-Binary-Search-Tree
*/

#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

Tree* build_bst(vector<int> &nums, int start, int end) {
    if (start > end)
        return NULL;
    int k = floor((end + start + 1)/2);
    Tree* root = new Tree();
    root -> val = nums[k];
    root -> left = build_bst(nums, start, k - 1);
    root -> right = build_bst(nums, k + 1, end);
    return root;
}

Tree* list_to_bst(vector<int>& nums) {
    return build_bst(nums, 0, nums.size() - 1);
}