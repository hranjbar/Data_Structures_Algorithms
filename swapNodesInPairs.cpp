/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * prev = dummy;
        ListNode * curr = head;
        ListNode * next, * nextnext;
        while (curr && curr->next){
            next = curr->next;
            nextnext = curr->next->next;
            // swap
            prev->next = next;
            curr->next = nextnext;
            next->next = curr;
            // increment
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
