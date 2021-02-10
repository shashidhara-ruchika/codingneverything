/*
https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *addednum = new ListNode(0);
        ListNode *addednumlist = addednum;
        
        int carry = 0;
        
        while(!(l1 == NULL && l2 == NULL && carry == 0)) {
            
            int val = carry;
            
            if (l1) {
                val += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2) {
                val += l2 -> val;
                l2 = l2 -> next;
            }
            
            ListNode *newnode = new ListNode(val % 10);
            addednum -> next = newnode;
            addednum = addednum -> next;
            
            carry = val / 10;        
        }
        
        if (l1)
            addednum -> next = l1;
        
        if (l2)
            addednum -> next = l2;
        
        return addednumlist -> next;        
        
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
    4
    9 9 9 9
    2
    9 9
    */
    
    /*
    8 9 0 0 1
    */

    Solution *soln = new Solution;

    int n11, n12;
    cin >> n11;
    ListNode *l11 = soln -> insert_list(n11);
    cin >> n12;
    ListNode *l12 = soln -> insert_list(n12);

    ListNode* addedList1 = soln -> addTwoNumbers(l11, l12);

    soln -> display_list(addedList1);

    return 0;
}