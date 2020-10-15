/*
https://leetcode.com/problems/merge-two-sorted-lists/
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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // if any one of the list is empty, return the other list
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        // initialize new list - root with header node = 0
        // initialize new list pointer - newl pointing to root
        ListNode root = ListNode(0);
        ListNode *newl = &root;       
        
        // until any one of the list pointers don't point to NULL
        while(l1 && l2) {
            
            if(l1 -> val < l2 -> val) {  
                newl -> next = l1;
                l1 = l1 -> next;
            }
            
            else {
                newl -> next = l2;
                l2 = l2 -> next;
            }
            
            newl = newl -> next;
           
        }
        
        // if l1 pointer doesn't point to NULL, 
        // merge the remaining l1 list
        if (l1)
            newl -> next = l1;
        // if l2 pointer doesn't point to NULL,
        // merge the remaining l2 list
        else
            newl -> next = l2;
        
        // return the list after header node
        return root.next;
        
    }
};