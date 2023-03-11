/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<int> preorder;
    void dfs(TreeNode * root){
        if (root){
            preorder.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "", s;
        char c;
        dfs(root);
        for (int & n : preorder) {
            s = "";
            do {
                c = n%10 + '0';
                s += c;
            } while (n /= 10);
            reverse(s.begin(), s.end());
            ans += s + '*';
        }
        return ans;
    }
    TreeNode * helper(vector<int> & pre, int st, int en){
        if (st > en) return nullptr;
        int rVal = pre[st];
        TreeNode * root = new TreeNode(rVal);
        int l_st = st + 1, l_en, r_st, r_en = en;
        int ix = l_st;
        for (; ix <= en && pre[ix] < rVal; ix++);
        l_en = ix - 1;
        r_st = l_en + 1;
        root->left = helper(pre, l_st, l_en);
        root->right = helper(pre, r_st, r_en);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int en = pre.size() - 1;
        return helper(pre, 0, en);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data<<endl;
        if (data.empty()) return nullptr;
        vector<int> trav;
        string s;
        int ans, n, x;
        for (char c : data){
            if (c == '*'){
                x = 1; ans = 0;
                for_each(s.rbegin(), s.rend(), [&ans, &n, &x](char l){
                    n = l - 48;
                    ans += n * x;
                    x *= 10;
                });
                trav.push_back(ans);
                s = "";
            }
            else s += c;
        }
        // for (int el : trav) printf("%d--", el); cout<<endl;
        // return nullptr;
        return bstFromPreorder(trav);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
