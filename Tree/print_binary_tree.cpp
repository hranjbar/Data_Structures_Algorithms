/*
Given the root of a binary tree, construct a 0-indexed m x n string
matrix res that represents a formatted layout of the tree. 
The formatted layout matrix should be constructed using the following rules:

The height of the tree is height and the number of rows m should be equal to height + 1.
The number of columns n should be equal to 2height+1 - 1.
Place the root node in the middle of the top row (more formally, 
at location res[0][(n-1)/2]).
For each node that has been placed in the matrix at position res[r][c], 
place its left child at res[r+1][c-2height-r-1] 
and its right child at res[r+1][c+2height-r-1].
Continue this process until all the nodes in the tree have been placed.
Any empty cells should contain the empty string "".
Return the constructed matrix res.

 

Example 1:


Input: root = [1,2]
Output: 
[["","1",""],
 ["2","",""]]
Example 2:


Input: root = [1,2,3,null,4]
Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
-99 <= Node.val <= 99
The depth of the tree will be in the range [1, 10].
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
    vector<vector<string>> printTree(TreeNode* root) {
        m = 0;  // m = height + 1
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            int sz = q.size();
            while (sz) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sz--;
            }
            m++;
        }
        int n = (1 << m) - 1;
        // printf("m=%i, n=%i\n", m, n);
        vector<vector<string>> ans(m, vector<string>(n, ""));
        int r = 0;
        int c = n / 2;
        write(ans, root, r, c);
        return ans;
    }
private:
    int m;
    void write(vector<vector<string>>& book, TreeNode * root, int r, int c)
    {
        if (root) {
            book[r][c] = to_string(root->val);
            if (m - 2 >= r) {
                int offset = 1 << (m - 2 - r);
                write(book, root->left, r + 1, c - offset);
                write(book, root->right, r + 1, c + offset);
            }
        }
    }
};
