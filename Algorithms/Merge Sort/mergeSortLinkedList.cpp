/*
Given the head of a linked list, return the list after sorting it in ascending order.
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
    ListNode* Merge(ListNode* l, ListNode* r) {
        ListNode * ret = new ListNode();
        ListNode * node = ret;
        while (l && r) {
            if (l->val < r->val) {node->next = l; l = l->next;}
            else {node->next = r; r = r->next;}
            node = node->next;
        }
        if (l) node->next = l;
        if (r) node->next = r;
        return ret->next; 
    }
    ListNode * Partition(ListNode * head){
        if (head && head->next){
            ListNode * dummy = new ListNode();
            dummy->next = head;
            ListNode * slow = dummy, * fast = dummy;
            while (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            ListNode * right = slow->next;
            slow->next = nullptr;
            ListNode * left = head;
            left = Partition(left);
            right = Partition(right);
            return Merge(left, right);
        } else return head;
    }
    ListNode* sortList(ListNode* head) {
        return Partition(head);
    }
};
