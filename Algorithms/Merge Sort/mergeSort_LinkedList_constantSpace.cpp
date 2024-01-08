/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time 
and O(1) memory (i.e. constant space)?
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
    ListNode* merge(ListNode* left, ListNode* right)
    {
        // termination
        if (!left) return right;
        if (!right) return left;

        // recursive merging
        ListNode* ret = nullptr;
        if (left->val < right->val) {
            ret = left;
            ret->next = merge(left->next, right);
        } else {
            ret = right;
            ret->next = merge(left, right->next);
        }
        return ret;
    }
    ListNode* sortList(ListNode* head) {
        // termination
        if (!head || !head->next) return head;
        
        // find middle of list
        ListNode *slow = head, *fast = head->next;
        while(fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        // partition
        ListNode* r = sortList(slow->next);
        slow->next = nullptr;   // truncate left half
        ListNode* l = sortList(head);

        // merge
        return merge(l, r);
    }
};
