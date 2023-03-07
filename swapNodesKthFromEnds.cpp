/**
 /*
 You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
 */
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * aPrev=dummy, * bPrev=dummy, * r=dummy;
        for (int i=1; i<k; i++){
            r = r->next;
            bPrev = bPrev->next;
        }
        while (r->next->next){
            r = r->next;
            aPrev = aPrev->next;
        }
        ListNode * a=aPrev->next, * b=bPrev->next;
        // printf("a:%d, b:%d\n", a->val, b->val);
        // swap
        aPrev->next = b;
        bPrev->next = a;
        ListNode * temp;
        temp = b->next;
        b->next = a->next;
        a->next = temp;
        return dummy->next;
    }
};
