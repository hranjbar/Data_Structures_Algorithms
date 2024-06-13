/*
Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, or 
transmitted across a network connection link to be reconstructed later in 
the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no 
restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.
Clarification: 
The input/output format is the same as how LeetCode serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and 
come up with different approaches yourself.
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
        return to_string(root->val) + "[" + 
        serialize(root->left) + "][" + 
        serialize(root->right) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int i = 0;
        string rval{""};
        while (i < data.length() && data[i] != '[') rval += data[i++];
        string left{""}, right{""};
        stack<char> brackets;
        if (i < data.length()) brackets.push(data[i++]); // openning '['
        while (i < data.length()) {
            if (data[i] == '[') brackets.push(data[i]);
            else if (data[i] == ']') brackets.pop();
            if (brackets.empty()) {i++; break;} // don't add closing ']'
            left += data[i++];
        }
        if (i < data.length()) brackets.push(data[i++]); // openning '['
        while (i < data.length()) {
            if (data[i] == '[') brackets.push(data[i]);
            else if (data[i] == ']') brackets.pop();
            if (brackets.empty()) break; // don't add closing ']'
            right += data[i++];
        }
        return new TreeNode(stoi(rval), deserialize(left), deserialize(right));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
