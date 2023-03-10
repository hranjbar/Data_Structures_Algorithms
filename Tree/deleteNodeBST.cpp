/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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
    int helper(TreeNode * root){
        TreeNode * parent = root;
        TreeNode * rightMost = root->left;
        if (!rightMost->right){
            root->left = rightMost->left;
            return rightMost->val;
        }
        while (rightMost && rightMost->right){
            parent = rightMost;
            rightMost = rightMost->right;
        }
        parent->right = rightMost->left;
        return rightMost->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key == root->val){
            if (!root->left && !root->right){   //leaf
                return nullptr;
            }
            else if (root->left){   // if this subtree has a left wing, replace its root with the right most leaf of the left wing
                root->val = helper(root);
            }
            else return root->right; // if no left wing, simply replace this subtree with its right wing
        }
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};
