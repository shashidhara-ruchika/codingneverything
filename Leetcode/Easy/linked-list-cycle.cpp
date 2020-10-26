/*
https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        
        if (head == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while (slow != fast) {
            
            if(fast == NULL || fast -> next == NULL)
                return false;
            
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return true;
    }

    ListNode* insert_list(int n, int pos) {
        
        if (n == 0) 
            return NULL;
        
        int num;
        cin >> num;
        ListNode *root = new ListNode(num);
        ListNode *curr = root, *newnode, *connectednode = NULL;

        if (pos == 0)
            connectednode = root;

        for (int i = 1; i < n; i++) {
            
            cin >> num;
            newnode = new ListNode(num);           

            curr -> next = newnode;
            curr = curr -> next;

            if (i == pos)
                connectednode = curr;
        }

        if (connectednode != NULL) 
            curr -> next = connectednode;

        return root;
    }

    void solve() {

        int n, pos;
        cin >> n >> pos;

        ListNode* l = insert_list(n, pos);

        cout << hasCycle(l) << endl;

        return;
    }
};


int main() {

    /*
    4 1
    3 2 0 -4
    */

    /*
    1
    */
   
    Solution soln;
    soln.solve();

    return 0;
}