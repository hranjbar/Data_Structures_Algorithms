/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

/**
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        int n = 0;
        for (ListNode * node=head; node!=nullptr; node=node->next) n++;
        if (n < k) return head;
        else {
            // reverse k nodes
            ListNode * prev=nullptr, * nxt=nullptr, * cur=head, * tail=head;
            for (int kx=0; kx<k; kx++){
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            tail->next = reverseKGroup(cur, k);
            return prev;
        }
    }
};
