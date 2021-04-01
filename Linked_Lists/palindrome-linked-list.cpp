/*
https://leetcode.com/problems/palindrome-linked-list/
*/

#include <bits/stdc++.h> 
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    
    ListNode *reverse_sll(ListNode *head) {
        
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;
        
        while (curr) {
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode *get_palindrome_middle(ListNode *head) {
        
        ListNode *fast = head;
        ListNode *slow = head;       
        
        bool odd = true;
        
        while (fast && fast -> next) {
            
            fast = fast -> next -> next;
            slow = slow -> next;            
            
            if (fast == NULL)
                odd = false;
        }
        
        if (odd)
            slow = slow -> next;
        
        return slow;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if (head == NULL || head -> next == NULL)
            return true;
        
        ListNode *left = head;
        ListNode *right = get_palindrome_middle(head);
        
        right = reverse_sll(right);
        
        while (left && right) {
            
            if (left -> val != right -> val)
                return false;
            
            left = left -> next;
            right = right -> next;
        }
        
        return true;
        
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
    5
    1 2 3 2 1
    */

    /*
    true
    */

    Solution *soln = new Solution;
    int n1;
    cin >> n1;

    ListNode *l1 = soln -> insert_list(n1);
    
    cout << soln -> isPalindrome(l1) << endl;

    return 0;

}    