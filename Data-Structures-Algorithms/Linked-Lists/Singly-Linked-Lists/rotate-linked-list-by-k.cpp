/*
https://binarysearch.com/problems/Rotate-Linked-List-by-K
*/

# include <bits/stdc++.h>

using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};

class rotateList {
    public:
        LLNode* insertList();
        LLNode* rotateKList(LLNode* node, int k);
        void displayList(LLNode *head);
};

LLNode* rotateList :: rotateKList(LLNode* node, int k) {
    
    int len = 0;
    LLNode *node_ptr = node;
   
    while(node_ptr -> next) {
        len++;        
        node_ptr = node_ptr -> next;
    }
    LLNode *last_node = node_ptr;
    int k2 = len - k + 1;
    
    int count = 0;
    if(k2 == 0 || k == 0)
        return node;
    
    LLNode *k_node;
    node_ptr = node;
    while(node_ptr -> next) {
        count++;
        if(count == k2)
            k_node = node_ptr;
        node_ptr = node_ptr -> next;
    }
   
    LLNode *new_head = k_node -> next;
    node_ptr -> next = node;
    k_node -> next = NULL;
    return new_head;
    
}

LLNode* rotateList :: insertList() {

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

void rotateList :: displayList(LLNode *head) {

    LLNode *curr = head;
    while (curr) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;
}

/*
Input 
4
1 2 3 4
3

Output
2 3 4 1
*/

int main() {
    rotateList *ll_ptr = new rotateList();
    LLNode *list = ll_ptr -> insertList();
    int k;
    cin >> k;
    ll_ptr -> rotateKList(list, k);
    ll_ptr ->displayList(list);
    return 0;
}