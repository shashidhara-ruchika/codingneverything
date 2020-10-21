/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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

    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr_node = head;
        ListNode* next_node;        
        
        while (curr_node != NULL && curr_node -> next != NULL) {
            
            next_node = curr_node -> next;
            
            if (next_node -> val == curr_node -> val) 
                curr_node -> next = next_node -> next;
            
            else
                curr_node = curr_node -> next;               
        }
        
        return head;        
    }

    ListNode* insert_list (int n) {

        if (n == 0)
            return NULL;
        
        int num;
        cin >> num;
        ListNode *root = new ListNode(num);
        ListNode *curr = root;
        ListNode *newnode;

        for (int i = 1; i < n; i++) {
            cin >> num;
            newnode = new ListNode(num);
            curr -> next = newnode;
            curr = curr -> next;
        }
        return root;
    }

    void display_list(ListNode *l) {

        while (l != NULL) {
            cout << l -> val << " ";
            l = l -> next;
        }
        cout << endl;
    }

    void solve() {

        int n;
        cin >> n;
        
        ListNode *l = insert_list(n);

        ListNode *newl = deleteDuplicates(l);
        display_list(newl);

        return;
    }
};

int main() {

    /*
    5
    1 1 2 3 3
    */
    
    /*
    1 2 3 
    */
    
    Solution soln;
    soln.solve();

    return 0;
}