# https://leetcode.com/problems/palindrome-linked-list/submissions/1219383336/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head

        # find middle wit slow
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # rev 2nd half
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp

        # check palindrome
        left = head
        right = prev

        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        
        return True

        


    def isPalindrome2(self, head: Optional[ListNode]) -> bool:
        stack = []

        curr = head
        while curr:
            stack.append(curr.val)
            curr = curr.next
        
        curr = head
        while (stack):
            rear = stack[-1]
            
            if (rear != curr.val):
                return False
            else:
                stack.pop()
                curr = curr.next
        
        return True


        