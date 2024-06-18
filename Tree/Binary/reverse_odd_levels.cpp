/*
Given the root of a perfect binary tree, reverse the node values 
at each odd level of the tree.
For example, suppose the node values at level 3 are 
[2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.
A binary tree is perfect if all parent nodes have two children 
and all leaves are on the same level.
The level of a node is the number of edges along the path between 
it and the root node.

Example 1:
Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed 
and become 5, 3.

Example 2:
Input: root = [7,13,11]
Output: [7,11,13]
Explanation: 
The nodes at level 1 are 13, 11, which are reversed and become 
11, 13.

Example 3:
Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation: 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 
2, 2, 2, 2, 1, 1, 1, 1 after the reversal.

Constraints:
The number of nodes in the tree is in the range [1, 214].
0 <= Node.val <= 105
root is a perfect binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : 
       val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
private:
    void dfs(TreeNode* l, TreeNode* r, int lev)
    {
        if (!l) return;
        if (lev & 0x1) swap(l->val, r->val);
        dfs(l->left, r->right, lev + 1);
        dfs(l->right, r->left, lev + 1);
    }
};

// alternate BFS solution
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        stack<int> st;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front(); q.pop();
                if (!(lev & 0x1)) {   // even
                    if (cur->left) {
                        st.push(cur->left->val);
                        st.push(cur->right->val);
                    }
                }
                else {cur->val = st.top();st.pop();}  // odd
                if (cur->left) {q.push(cur->left); q.push(cur->right);}
            }
            lev++;
        }
        return root;
    }
};
