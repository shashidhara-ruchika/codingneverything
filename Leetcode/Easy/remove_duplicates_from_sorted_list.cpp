/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
};