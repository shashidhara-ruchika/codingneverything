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
    ListNode* removeElements(ListNode* head, int val) {
        
        // remove all continuous nodes with same val
        while (head != NULL && head -> val == val)
            head = head -> next;
        
        if (head == NULL)
            return NULL;
        
        ListNode *curr = head -> next, *prev = head;
        
        while (curr != NULL) {
            
            if (curr -> val == val) {               
                prev -> next = curr -> next;
                curr = prev -> next;  
            }            
            else {
                prev = curr;
                curr = curr -> next;
            }
            
        }
        return head;        
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

    void solve() {

        int n;
        cin >> n;
        ListNode *l = insert_list(n);

        int val;
        cin >> val;

        ListNode *l_no_val = removeElements(l, val);
        display_list(l_no_val);
    }

};

int main() {

    /*
    10
    6 6 6 1 2 3 6 4 5 6
    6
    */
    
    /*
    1 2 3 4 5
    */
    
    Solution soln;
    soln.solve();

    return 0;
}