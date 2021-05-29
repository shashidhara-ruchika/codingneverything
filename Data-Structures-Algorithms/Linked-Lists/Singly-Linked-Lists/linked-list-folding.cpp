/*
https://binarysearch.com/problems/Linked-List-Folding
*/

#include <bits/stdc++.h> 
using namespace std; 


class LLNode {
    public:
        int val;
        LLNode *next;
};

LLNode* insert_list() {
    int n;
    cin >> n;

    if (n == 0)
        return NULL;

    int num;
    cin >> num;
    LLNode *root = new LLNode();
    root -> val = num;
    root -> next = NULL;
    LLNode *curr = root;
    
    while (n-- > 1) {
        cin >> num;
        LLNode *new_node = new LLNode();
        new_node -> val = num;
        new_node -> next = NULL;
        curr -> next = new_node;
        curr = curr -> next;
    }

    return root;
}

LLNode* folded_link_list(LLNode* node) {
    vector<int> list;
    LLNode *node_ptr = node;
    while(node_ptr) {
        list.push_back(node_ptr -> val);
        node_ptr = node_ptr -> next;
    }

    LLNode *new_list = new LLNode();    
    new_list -> val = 0;
    new_list -> next = NULL;
    LLNode *new_list_ptr = new_list;
    int start, end;
    if (list.size() % 2)
    {
        start = list.size()/ 2 - 1;
        end = list.size()/ 2 + 1;
    }
    else {
        start = list.size() / 2 - 1;
        end = list.size() / 2;
    }

    while(start >= 0 && end <= list.size()) {
        LLNode *new_node = new LLNode();
        new_node -> val = list[start] + list[end];
        new_list_ptr -> next = new_node;
        new_list_ptr = new_list_ptr -> next;
        start--;
        end++;
    }

    if (list.size() % 2) {
        new_list -> val = list[list.size()/2];
        return new_list;
    }
    
    return new_list -> next;
}

/*
Input
7
1 2 3 4 5 6 7

Output
4 8 8 8
*/

int main() {
    LLNode* list = insert_list();
    LLNode* folded_list = folded_link_list(list);
    LLNode *ptr = folded_list;
    while(!ptr) {
        cout << ptr -> val << " ";
        ptr = ptr -> next;
    }
    cout << endl;
    return 0;
}