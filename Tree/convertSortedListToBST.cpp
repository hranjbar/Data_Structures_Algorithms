/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       if (!head) return nullptr;
       if (!head->next) return new TreeNode(head->val);
       ListNode * dummy = new ListNode();
       dummy->next = head;
       ListNode * slow = dummy, * fast = dummy;
       while (fast->next && fast->next->next) {
           fast = fast->next->next;
           slow = slow->next;
       }
       TreeNode * root = new TreeNode(slow->next->val);
       root->right = sortedListToBST(slow->next->next);
       slow->next = nullptr;
       root->left = sortedListToBST(head);
       return root;
    }
};
