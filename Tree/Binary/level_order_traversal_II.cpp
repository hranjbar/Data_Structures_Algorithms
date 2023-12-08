/*
Given the root of a binary tree, return the bottom-up level 
order traversal of its nodes' values. 
(i.e., from left to right, level by level from leaf to root).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> out;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> row;
            while (sz>0) {
                TreeNode* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                sz--;
            }
            out.push_back(row);
        }
        vector<vector<int>> ans(out.size());
        for (int i=out.size()-1; i>=0; i--) {
            for (int j=0; j<out[i].size(); j++) 
                ans[out.size()-i-1].push_back(out[i][j]);
        }
        return ans;
    }
};
