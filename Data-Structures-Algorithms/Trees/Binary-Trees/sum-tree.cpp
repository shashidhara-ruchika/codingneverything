/*
https://binarysearch.com/problems/Sum-Tree
*/

# include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

class sum_tree {
    private:
        Tree* root;
        map<Tree*, bool> status;
    public:
        sum_tree(Tree* root);
        void add_status(Tree* root);
        bool check_status();
};

sum_tree :: sum_tree(Tree* root) {
    this -> root = root;
    this -> add_status(this -> root);
}

void sum_tree :: add_status(Tree* root) {
    if(root) {
        int count = 0;
        int sum = 0;
        bool sum_check = true;
        
        if(root -> left) {
            add_status(root -> left);
            count++;
            sum += root -> left -> val;
        }

        if(root -> right) {
            add_status(root -> right);
            count++;
            sum += root -> right -> val;
        }
        
        if(count != 0 && root -> val != sum) {
            sum_check = false;
        }      

        this -> status[root] = sum_check;
    }
}

bool sum_tree :: check_status() {
    for(auto m_it : this -> status) {
        if(!m_it.second)
            return false;
            //cout << m_it.first -> val << " ";
            //cout << m_it.second << endl;       
    }
    return true;
}

bool solve(Tree* root) {
    sum_tree *st = new sum_tree(root);
    return st -> check_status();
}

//[9, [1, null, null], [8, [6, [6, null, null], null], [2, null, null]]]
//[0, [1, null, null], null]