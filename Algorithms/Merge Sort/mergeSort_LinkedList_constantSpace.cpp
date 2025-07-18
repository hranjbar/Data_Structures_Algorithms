/*
Given the head of a linked list, return the list after sorting it 
in ascending order.

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
    ListNode* sortList(ListNode* head) {
        return partition(head);
    }
    private:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if (not left) return right;
        if (not right) return left;

        ListNode* ret;
        if (left->val < right->val){
            ret = left;
            ret->next = merge(left->next, right);
        }
        else {
            ret = right;
            ret->next = merge(left, right->next);
        }
        return ret;
    }
    ListNode* partition(ListNode* head)
    {
        // 0. termination 
        if (not head or not head->next) return head;

        // 1. find middle of list (mid = l+(r-l)/2)
        auto* slow = head;
        auto* fast = head->next;
        while (fast){
            fast = fast->next;
            if (fast){
                slow = slow->next;
                fast = fast->next;
            }
        }

        // 2. partition
        auto* right = partition(slow->next);
        slow->next = nullptr;   // truncate left half
        auto* left = partition(head);
        return merge(left, right);
    }
};
