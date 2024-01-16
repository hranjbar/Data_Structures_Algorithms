/*
Given two integer arrays inorder and postorder where inorder is the 
inorder traversal of a binary tree and postorder is the postorder 
traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* dfs(vector<int>& ino, vector<int>& pos, int a, int b, int c, int d)
    {
        if (a>b || c>d) return nullptr; // terminal
        int val = pos[d];
        TreeNode* root = new TreeNode(val);
        int ix; // ix : [a,b]
        for (int i=a; i<=b; i++) {if (ino[i]==val) {ix=i; break;}}
        root->right = dfs(ino, pos, ix+1, b, d-(b-ix), d-1);
        root->left = dfs(ino, pos, a, ix-1, c, d-(b-ix)-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
/* ranges are inorder:[a,b] and postorder:[c,d] inclusive */
