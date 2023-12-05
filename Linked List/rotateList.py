'''
Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head: return None    # edge case
        n = head
        size = 0
        # find length of list
        while n:
            n=n.next
            size += 1
        k = k%size   # in case k >= size
        if not k: return head   # edge case
        # get to (size-k)-th link
        dum, dum.next= ListNode(), head
        n = dum
        for _ in range(size-k):
            n=n.next
        # head of answer list is here
        ans = n.next
        # kill link
        n.next = None
        # move onto the end of list
        dum.next, m = ans, dum
        while m.next: m=m.next
        # link back to original head
        m.next=head
        return ans
