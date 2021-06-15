/*
https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* rec_swap(ListNode* node) { 
            
            if(!node || !(node -> next))
                return node;
            
            ListNode* temp = node -> next;
            node -> next = rec_swap(temp -> next);        
            temp -> next = node;
            
            return temp;
        }
    
public:
    ListNode* swapPairs_rec(ListNode* head) {
        return rec_swap(head);
    }

    ListNode* swapPairs(ListNode* head) {       
        
        if ( ! head || ! (head -> next) )
            return head;
        
        ListNode *node_ptr = head;
        ListNode *node1 = head;
        ListNode *node2 = head -> next;
        
        node1 -> next = node2 -> next;
        head = node2;
        node2 -> next = node1;
        node_ptr = node1;
        
        while (node_ptr -> next && node_ptr -> next -> next) {
            
            node1 = node_ptr -> next;
            node2 = node_ptr -> next -> next;
            
            node1 -> next = node2 -> next;
            node_ptr -> next = node2;
            node2 -> next = node1;
            
            node_ptr = node1;            
        }
        
        return head;
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
    3 8 9 6 8 9 4
    */

    /*
    8 3 6 9 9 8 4
    */

    Solution *soln = new Solution();
    int n;
    cin >> n;
    ListNode *list = soln -> insertList(n);
    ListNode* swapped_list = soln -> swapPairs(list);
    soln -> displayList(swapped_list);

    return 0;
}