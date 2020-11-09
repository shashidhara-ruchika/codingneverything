/*
https://leetcode.com/problems/add-two-numbers-ii/
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
    int lenList(ListNode* l) {
        ListNode* temp = l;
        int len = 0;
        while(temp) {
            temp = temp -> next;
            len++;
        }
        return len;
    }
    
    ListNode* recAdd(ListNode* l1, int len1, ListNode* l2, int len2, int& carry) {
        
        if(len1 == 0 && len2 == 0) {
            return NULL;
        }
        
        ListNode* ans = new ListNode();
        ListNode* res;

        if(len1 == len2) {
            
            res = recAdd(l1->next, len1-1, l2->next, len2-1, carry);
            carry += l1->val + l2->val;
        }
        else if(len1 > len2) {
            res = recAdd(l1->next, len1-1, l2, len2, carry);
            carry += l1->val;
        }
        else {
            res = recAdd(l1, len1, l2->next, len2-1, carry);
            carry += l2->val;
        }

        ans->val = carry%10;
        carry /= 10;
        ans->next = res;

        return ans;
    }
    
    ListNode* addTwoNumbers_rec(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;

        int len1 = lenList(l1), len2 = lenList(l2);
        
        int carry = 0;
        auto ans = recAdd(l1, len1, l2, len2, carry);
        
        if(carry) ans = new ListNode(carry, ans);
        return ans;
    }

    stack<int> listToStack(ListNode* l) {
        
        stack<int> s;
        
        ListNode* temp = l;
        
        while(temp) {
            s.push(temp -> val);
            temp = temp -> next;
        }
        
        return s;
    }
    
    ListNode* addTwoNumbers_stack(ListNode* l1, ListNode* l2) {
        
        ListNode *head = NULL;
        
        stack<int> s1 = listToStack(l1);
        stack<int> s2 = listToStack(l2);
        
        int carry = 0, add1, add2;
        
        while( !s1.empty() || !s2.empty() || carry ) {
            
            if ( !s1.empty() ) {
                add1 = s1.top();
                s1.pop();
            }
            else
                add1 = 0;
            
            
            if ( !s2.empty() ) {
                add2 = s2.top();
                s2.pop();
            }
            else 
                add2 = 0;
            
            int addedSum = add1 + add2 + carry;
            
            ListNode* node = new ListNode(addedSum % 10, head);
            //node -> next = head;
            head = node;
            
            carry = addedSum / 10;
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
};

int main() {

    /*
    4
    7 2 4 3
    3
    5 6 4
    4
    9 9 9 9
    2
    9 9
    */
    
    /*
    7 8 0 7
    1 0 0 9 8
    */

    Solution *soln1 = new Solution;
    int n11, n12;
    cin >> n11;
    ListNode *l11 = soln1 -> insert_list(n11);
    cin >> n12;
    ListNode *l12 = soln1 -> insert_list(n12);
    ListNode* addedList1 = soln1 -> addTwoNumbers_rec(l11, l12);
    soln1 -> display_list(addedList1);

    Solution *soln2 = new Solution;
    int n21, n22;
    cin >> n21;
    ListNode *l21 = soln2 -> insert_list(n21);
    cin >> n22;
    ListNode *l22 = soln2 -> insert_list(n22);
    ListNode* addedList2 = soln1 -> addTwoNumbers_stack(l21, l22);
    soln2 -> display_list(addedList2);

    return 0;
}