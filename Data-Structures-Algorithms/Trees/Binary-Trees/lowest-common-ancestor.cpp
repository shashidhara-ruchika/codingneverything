/*
https://binarysearch.com/problems/Lowest-Common-Ancestor
*/

#include <bits/stdc++.h> 
using namespace std; 


class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};


void postorder(Tree* root, int a, int b, bool *isa, bool *isb, int *ans) {

    if (!root)
        return;
    if (*ans != -1)
        return;

    bool oldisa = *isa;
    bool oldisb = *isb;

    postorder(root -> left, a, b, isa, isb, ans);
    postorder(root -> right, a, b, isa, isb, ans);

    if (root -> val == a) 
        *isa = true;
    if (root -> val == b)
        *isb = true;

    if (!oldisa && !oldisb && *isa && *isb && *ans == -1)
        *ans = root -> val;

}

int solve(Tree* root, int a, int b) {
    bool isa = false;
    bool isb = false;
    int ans = -1;
    postorder(root, a, b, &isa, &isb, &ans);
    return ans;
}