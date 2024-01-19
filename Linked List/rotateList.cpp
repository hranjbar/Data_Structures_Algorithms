/*
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
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;  // trivial
        int len=0;
        ListNode* cur=head;
        while(cur) {cur=cur->next; len++;} // find length of list
        k=k%len; // modify k
        if (k==0) return head; // trivial
        ListNode* dum=new ListNode(0,head);
        cur=dum;
        for(int i=0; i<len-k; i++) cur=cur->next; // find link before new head
        dum=new ListNode(0,cur->next); // dum->next will be new head
        cur->next=nullptr; // kill cycle
        cur=dum;
        while(cur->next) cur=cur->next; // find old tail
        cur->next=head; // point old tail to old head
        return dum->next;
    }
};
