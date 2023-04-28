"""
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, 
and return the reversed list.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        node = dummy
        for _ in range(left - 1):   # -1 because left and right is 1-based indexed
            node = node.next
        # reverse
        prev = node.next
        cur = prev.next 
        prev.next = None
        for _ in range(left, right):
            if cur:
                cur.next, prev, cur = prev, cur, cur.next
            else:
                break
        # stich head of reversed
        node.next = prev
        # stich tail of reversed to cur
        n = prev
        while n.next:
            n = n.next
        n.next = cur
        
        return dummy.next        
