/*
Given the root of a binary tree, return the preorder
traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do 
it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
       : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Morris Traversal 
        unordered_set<TreeNode*> vis;
        vector<int> ans;
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *pred = cur->left;
                while (pred->right) pred = pred->right;
                pred->right = cur;
                TreeNode *left = cur->left;
                cur->left = nullptr;    // kill left child
                ans.push_back(cur->val); vis.insert(cur); // visit cur now
                cur = left;
            } else {
                if (vis.count(cur)==0) ans.push_back(cur->val); 
                // visit only if not already visited
                // adding to vis is not necessary here, can you tell why?!
                cur = cur->right;
            }
        }
        return ans;
    }
};
