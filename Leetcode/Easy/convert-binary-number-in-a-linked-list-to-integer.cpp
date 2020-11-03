/*
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        
        ListNode *curr = head;
        
        int num10 = 0;
        
        while (curr != NULL) {
            
            num10 = num10 << 1;
            num10 += curr -> val;
            
            //cout << num10 << endl;
            curr = curr -> next;
        }
        
        return num10;
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
};

int main() {

    /*
    15
    1 0 0 1 0 0 1 1 1 0 0 0 0 0 0
    */

    /*
    18880
    */

    Solution *soln = new Solution;
    int n;
    cin >> n;
    ListNode *l = soln -> insert_list(n);
    cout << soln -> getDecimalValue(l) << endl;
    
    return 0;
}