/*
https://leetcode.com/problems/remove-linked-list-elements/
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
public:

    // insertion of node into list
    ListNode* insert_node(ListNode* head, ListNode* node) {
        
        ListNode *curr = head, *prev = NULL;
        while(curr != NULL && curr -> val <= node -> val) {
            prev = curr;
            curr = curr -> next;
        }
        
        if(curr == head) {
            node -> next = curr;
            head = node;
        }
        else {
            prev -> next = node;
            node -> next = curr;
        }       
        
        return head;
    }
    
    // n^2 insertion sort
    // create a new pointer to sortedList
    // traverse through list passed and keep inserting node from this list into sortedList
    // Complexity: time - O(n^2), space - O(1)
    ListNode* insertionSortList(ListNode* head) {
        
        if (head == NULL || head -> next == NULL)
            return head;
        
        ListNode *curr = head -> next;
        
        ListNode *sorted_l = head;                
        sorted_l -> next = NULL;
        
        while (curr != NULL) {
            ListNode *node = curr;
            curr = curr -> next;
            sorted_l = insert_node(sorted_l, node);
        }        
        
        return sorted_l;        
    }

    ListNode* insert_node_btw_0_count(ListNode* head, ListNode* node, int count) {
        
        ListNode *curr = head, *prev = NULL;
        while(curr != NULL && count-- > 0 && curr -> val <= node -> val) {
            prev = curr;
            curr = curr -> next;
        }
        
        if(curr == head) {
            node -> next = curr;
            head = node;
        }
        else {
            prev -> next = node;
            node -> next = curr;
        }       
        
        return head;
    }
    
    // for iteration num = 0
    // takes the last node and inserts at correct position from 0 to iteration num
    // Complexity: time - O(n^3), space - O(1)
    ListNode* insertionSortList_n3_algo(ListNode* head) {
        
        int num_nodes = 0;        
        ListNode *curr = head;        
        
        while(curr != NULL) {
            curr = curr -> next;
            num_nodes++;
        }
        
        if (num_nodes <= 1)
            return head;
        
        ListNode * prev;
        ListNode *l = head;
        ListNode *node;
        
        for(int i = 0; i < num_nodes; i++) {
            
            curr = l;            
            while (curr -> next != NULL) {
                prev = curr;
                curr = curr -> next;
            }
            
            node = curr;
            prev -> next = curr -> next;

            l = insert_node_btw_0_count(l, node, i);          
        }
        
        return l;        
    }

    ListNode* insert_list(int n) {

        if (n == 0)
            return NULL;
        
        int num;
        cin >> num;
        ListNode* root = new ListNode(num);
        ListNode* curr = root;
        ListNode *newnode;

        for(int i = 1; i < n; i++) {
            cin >> num;
            newnode = new ListNode(num);
            curr -> next = newnode;
            curr = curr -> next;
        }
        
        return root;
    }

    void display_list(ListNode *l) {

        while(l != NULL) {
            cout << l -> val << " ";
            l = l -> next;
        }
        cout << endl;
    }
};

int main() {
    /*
    5
    -1 5 3 0 4
    4
    6 0 7 3
    */
    
    /*
    -1 0 3 4 5
    0 3 6 7
    */
   
   Solution *soln = new Solution;
   int n1;
   cin >> n1;
   ListNode *l1 = soln -> insert_list(n1);
   ListNode *sorted_l1 = soln -> insertionSortList(l1);
   soln -> display_list(sorted_l1);
   
   Solution *soln_n3_algo = new Solution;
   int n2;
   cin >> n2;
   ListNode *l2 = soln_n3_algo -> insert_list(n2);
   ListNode *sorted_l2 = soln_n3_algo -> insertionSortList(l2);
   soln_n3_algo -> display_list(sorted_l2);
    
   return 0;
}