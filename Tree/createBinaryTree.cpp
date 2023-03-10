/*
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> isChild;
        unordered_map<int, TreeNode *> hash;
        TreeNode * parent, * child;
        for (vector<int> des : descriptions) {
            if (!hash.count(des[0])) hash[des[0]] = new TreeNode(des[0]);
            parent = hash[des[0]];
            if (!hash.count(des[1])) hash[des[1]] = new TreeNode(des[1]);
            child = hash[des[1]];
            isChild.insert(des[1]);
            if (des[2]) parent->left = child;
            else parent->right = child;
        }
        for (auto node : hash){
            if (!isChild.count(node.first)) return node.second;
        }
        return nullptr;
    }
};
