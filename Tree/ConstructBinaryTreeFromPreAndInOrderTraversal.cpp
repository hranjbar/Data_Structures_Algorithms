/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.
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
    TreeNode * helper(vector<int> & pre, int pre_st, int pre_en, vector<int> & in, int in_st, int in_en){
        if (pre_st>pre_en || in_st>in_en) return nullptr;   // recursion's terminal
        int rootVal = pre[pre_st], left_pre_st, left_pre_en, right_pre_st, left_in_en, right_in_st, ix;
        TreeNode * root = new TreeNode(rootVal);
        int rvix;   // find root value index
        for (int jx=in_st; jx<=in_en; jx++) {if (in[jx]==rootVal) {rvix=jx; break;}}
        // in-order
        left_in_en = rvix-1;
        right_in_st = rvix+1;
        // pre-order
        left_pre_st = pre_st + 1;
        left_pre_en = left_pre_st + left_in_en - in_st; // because left_pre_en-lef_pre_st = left_in_en-left_in_st;
        right_pre_st = left_pre_en + 1;
        root->left = helper(pre, left_pre_st, left_pre_en, in, in_st, left_in_en);
        root->right = helper(pre, right_pre_st, pre_en, in, right_in_st, in_en);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
