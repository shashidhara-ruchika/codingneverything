// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        ListNode curr = head;
        ListNode next;

        while(curr != null && curr.next != null) {
            next = curr.next;

            if (curr.val == next.val) {
                curr.next = next.next;
            } else {
                curr = curr.next;
            }
        } 

        return head;
        
    }
}

