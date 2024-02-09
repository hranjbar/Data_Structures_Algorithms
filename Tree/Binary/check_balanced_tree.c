/*
Given a binary tree, determine if it is 
height-balanced
 
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Height(struct TreeNode* root)
{
    if (!root) return -1;
    int lh = Height(root->left);
    if (lh == INT_MIN) return INT_MIN;
    int rh = Height(root->right);
    if (rh == INT_MIN) return INT_MIN;
    if (abs(lh - rh) > 1) return INT_MIN;
    else return 1 + (lh > rh ? lh : rh);
}
bool isBalanced(struct TreeNode* root) {
    return Height(root) != INT_MIN;
}
