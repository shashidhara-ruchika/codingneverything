/*
https://leetcode.com/problems/reverse-linked-list/
*/

# include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* rec_rev_list(ListNode* node) {
        
        if( !(node) || !(node -> next) )
            return node;
        
        ListNode* temp = rec_rev_list(node -> next);
        node -> next -> next = node;
        node -> next = NULL;
        return temp;
    }
    
public:    
    ListNode* reverseList_rec(ListNode* head) {
        return rec_rev_list(head);        
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr_node = NULL;
        ListNode* node_ptr = head;
        
        while(node_ptr) {
            ListNode* next_node = node_ptr -> next;
            node_ptr -> next = curr_node;
            curr_node = node_ptr;
            node_ptr = next_node;
        }
        
        return curr_node;
    }

    ListNode *insertList(int n) {

        if (n == 0)
            return NULL;

        int num;
        cin >> num;
        ListNode *root = new ListNode(num);
        ListNode *curr = root;
        
        while (n-- > 1) {
            cin >> num;
            ListNode *new_node = new ListNode(num);
            curr -> next = new_node;
            curr = curr -> next;
        }

        return root;
    }

    void displayList(ListNode *head) {

        ListNode *curr = head;
        while (curr) {
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
};

int main() {

    /*
    7
    1 2 3 4 5 6 7
    */

    /*
    7 6 5 4 3 2 1
    */

    Solution *soln = new Solution();
    int n;
    cin >> n;
    ListNode *list = soln -> insertList(n);
    ListNode* swapped_list = soln -> reverseList(list);
    soln -> displayList(swapped_list);

    return 0;
}