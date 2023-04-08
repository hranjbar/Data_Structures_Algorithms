/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
*/

class Solution {
    struct TrieNode {
        char val;
        bool terminal;
        vector<TrieNode *> children;
        TrieNode () {val = '\0'; terminal = false; children = vector<TrieNode *>(26, nullptr);}
        TrieNode (char c) {val = c; terminal = false; children = vector<TrieNode *>(26, nullptr);}
    };
    void build(TrieNode * root, vector<string> & words) {  // insert all words into Trie dictionary
        for (string & word : words) {
            TrieNode * node = root;
            for (char & c : word){
                int ci = c - 'a';
                if (!node->children[ci]) node->children[ci] = new TrieNode(c);
                node = node->children[ci];
            }
            node->terminal = true;
        }
    }
    int m, n;
    vector<string> ans;
    void dfs(vector<vector<char>> & b, TrieNode * node, int i, int j, string word = "") {
        if (i<0 || j<0 || i>=m || j>=n) return;
        char c = b[i][j];
        int ci = c - 'a';
        if (c == '*' || node->children[ci] == nullptr) return;
        word.push_back(c);
        if (node->children[ci]->terminal) {
            ans.push_back(word); 
            node->children[ci]->terminal = false; // when found, avoid re-finding
        }
        b[i][j] = '*';
        dfs(b, node->children[ci], i+1, j, word);
        dfs(b, node->children[ci], i-1, j, word);
        dfs(b, node->children[ci], i, j+1, word);
        dfs(b, node->children[ci], i, j-1, word);
        b[i][j] = c;
        word.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode * root = new TrieNode();
        build(root, words);
        m = board.size(); n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j);
            }
        }
        return ans;
    }
};
