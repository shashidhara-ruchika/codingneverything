/*
https://binarysearch.com/problems/Swap-Kth-Node-Values
*/

# include <bits/stdc++.h>

using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};
 
class Swap_k_begin_end {
        
    public:
        LLNode* insertList();
        LLNode* kswap(LLNode* node, int k);
        void displayList(LLNode *head);
};

LLNode* Swap_k_begin_end :: insertList() {

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

void Swap_k_begin_end :: displayList(LLNode *head) {

    LLNode *curr = head;
    while (curr) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;
}

LLNode*  Swap_k_begin_end :: kswap(LLNode* node, int k) {

    LLNode *node_ptr = node;
    LLNode* k_begin_node;
    LLNode* k_end_node;

    int ll_len = 0;
    
    while(node_ptr) {
        if (ll_len == k) {
            k_begin_node = node_ptr;
        }
        ll_len++;
        node_ptr = node_ptr -> next;
    }
    
    int k_end_val = ll_len - k - 1;
    node_ptr = node;    
    int count = 0;
    while(node_ptr) {
        if(count == k_end_val) {
            k_end_node = node_ptr;
        }
        count++;
        node_ptr = node_ptr -> next;
    }
 
    int temp = k_begin_node -> val;
    k_begin_node -> val = k_end_node -> val;
    k_end_node -> val = temp;
    return node;
}

/*
Input 
6
1 2 3 4 5 6

Output
1 5 3 4 2 6
*/

int main() {
    Swap_k_begin_end *ll_swap_ptr = new  Swap_k_begin_end();
    LLNode *list = ll_swap_ptr -> insertList();
    int k;
    cin >> k;
    ll_swap_ptr -> kswap(list, k);
    ll_swap_ptr ->displayList(list);
    return 0;
}