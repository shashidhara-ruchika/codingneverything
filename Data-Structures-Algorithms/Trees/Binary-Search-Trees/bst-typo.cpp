/*
https://binarysearch.com/problems/Binary-Search-Tree-Typo
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class bst {
    private:
        Tree* root;
        vector<pair<Tree*, int>> inorder;
    public:
        bst(Tree* root);
        void traverse_inorder(Tree* root);
        void correct_bst();
        Tree* get_root();
};

bst :: bst(Tree* root) {
    this -> root = root;
    traverse_inorder(root);
}

void bst :: traverse_inorder(Tree* root) {
    if(root) {
        traverse_inorder(root -> left);
        this -> inorder.push_back({root, root -> val});
        traverse_inorder(root -> right);
    }
}
Tree* bst :: get_root() {
    return this -> root;
}


void bst :: correct_bst() {
    for(int i = this -> inorder.size() - 1; i > 0; i--) {
        
        if(this -> inorder[i].second < this -> inorder[i - 1].second) {
            
            int j = i - 1;
            
            while(j >= 0 && this -> inorder[i].second < this -> inorder[j].second)
                j--;
            //cout << inorder[i].first -> val << endl;
            //cout << inorder[j + 1].first -> val << endl;

            int temp = inorder[i].first -> val;
            inorder[i].first -> val = inorder[j + 1].first -> val;
            inorder[j + 1].first -> val = temp;
            
            //cout << inorder[i].first -> val << endl;
            //cout << inorder[j + 1].first -> val << endl;
            return;
        }
    }
}

Tree* solve(Tree* root) {
    bst *bst_ptr = new bst(root);
    bst_ptr -> correct_bst();
    return bst_ptr -> get_root();
}

//[2, [5, null, null], [7, [1, null, null], [8, null, null]]]