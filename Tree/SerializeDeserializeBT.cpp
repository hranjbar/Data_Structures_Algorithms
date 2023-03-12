/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree: 
https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation-
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        int rval = root->val;
        string s = "";
        s = to_string(rval);
        s += "[" + serialize(root->left) + "][" + serialize(root->right) + "]";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int ix=0;
        string s="";
        for (; ix<data.length(); ix++){
            if (data[ix]=='[') break;
            s += data[ix];
        }
        int rval = stoi(s);
        TreeNode * root = new TreeNode(rval);
        string l="", r="";
        int close=0, open=0;
        ix++; open++;   // skip '['
        for (; ix < data.length(); ix++){
            if (data[ix]=='[') open++;
            if (data[ix]==']') close++;
            if (close==open) break;
            l += data[ix];
        }
        ix += 2;    // skip "]["
        for (; ix<data.length()-1; ix++) r += data[ix];
        root->left = deserialize(l);
        root->right = deserialize(r);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
