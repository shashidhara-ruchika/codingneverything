// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    public ListNode removeNthFromEnd(ListNode head, int n) {

        if (head.next == null) {
            head = null;
            return head;
        }

        ListNode slow = head;
        ListNode fast = head;

        for (int i = 0 ; i < n - 1 && fast != null; i++) {
            fast = fast.next;
        }

        ListNode prev = head;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next;
        }

        if (slow == head) {
            head = slow.next;
        }

        prev.next = slow.next;
        
        return head;
    }
}