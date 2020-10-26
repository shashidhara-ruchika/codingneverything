/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

# include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // Two pointer solution, first p1 points to headA & p2 points to headB
    // once p1 reaches end, p1 points to headB
    // once p2 reached end, p2 points to headA
    ListNode *getIntersectionNode_twopointer(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        while (p1 != p2) {
            
            p1 = p1 -> next;
            p2 = p2 -> next;
            
            // if lists have intersection, reference to the intersection is returned
            // if lists don't have intersection, since both p1 & p2 will be pointing 
            // to end of linked lists i.e. NULL, NULL itself will be returned
            if (p1 == p2)
                return p1;
            
            if (p1 == NULL)
                p1 = headB;
            
            if (p2 == NULL)
                p2 = headA;            
        }        
        return p1;
    }

    ListNode *getIntersectionNode_diffinlen_pointers(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL)
            return NULL;
        
        int lenA = 0, lenB = 0, goaheadby;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(true) {
            
            // case when both linked list length are same & there is an intersection
            if (a == b && a != NULL && b != NULL) 
                return a;
            
            if (a != NULL) {
                a = a-> next;
                lenA++;
            }
            if (b != NULL) {
                b = b -> next;
                lenB++;
            }
            
            if (a == NULL && b == NULL)
                break;
        }
        
        // start traversing the linked lists again from head
        // but goaheadby the difference in lengths in the longer list
        a = headA;
        b = headB;
        
        if (lenA > lenB) {
            goaheadby = lenA - lenB;
            while (goaheadby-- > 0) 
                a = a -> next;
        }
        else {
            goaheadby = lenB - lenA;
            while (goaheadby-- > 0)
                b = b -> next;            
        }
        
        while(a != NULL) {
            // case when both linked list lengths are different & there is an intersection
            if (a == b)
                return a;
            a = a -> next;
            b = b -> next;
        }
        
        // case when there is no intersection whatever the length of the linked lists are
        return NULL;
    }
};

/*
8
[4,1,8,4,5]
[5,6,1,8,4,5]
2
3
*/

/*
Intersected at '8'
*/
