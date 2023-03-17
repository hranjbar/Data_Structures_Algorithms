/*
Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode * node = head;
        int n=0; 
        while (node) {
            n++;
            node = node->next;
        }
        k = k % n;
        if (k != 0){
            ListNode * dummy = new ListNode();
            dummy->next = head;
            ListNode * node = dummy;
            for (int i=k; i<n; i++) node = node->next;
            ListNode * h2 = node->next; // remainder of head is h2
            node->next = nullptr; // cut remainder of head
            
            // append head to h2
            dummy = new ListNode();
            dummy->next = h2;
            node = dummy;
            for (int i=0; i<k; i++) node = node->next;
            node->next = head;
           
            return h2;
        }
        return head;
    }
};
