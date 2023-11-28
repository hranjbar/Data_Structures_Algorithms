/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from 
products after each character of searchWord is typed. Suggested 
products should have common prefix with searchWord. If there are
more than three products with a common prefix return the three 
lexicographically minimums products.

Return a list of lists of the suggested products after each 
character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot",
"monitor","mousepad"], 
searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],["mouse","mousepad"],
["mouse","mousepad"]]
Explanation: products sorted lexicographically = 
["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we 
show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system 
suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],
["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested 
while typing the search word.
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/

class Solution {
public:
    struct TrieNode
    {
        char val;
        bool terminal;
        vector<TrieNode*> children;
        TrieNode() : val('\0'), terminal(false), children(vector<TrieNode*>(26, nullptr)){}
        TrieNode(char c) : val(c), terminal(false), children(vector<TrieNode*>(26, nullptr)){}
    };
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        ROOT = new TrieNode();
        for (string & product : products) insert(product);
        vector<string> matches;
        string word = "";
        TrieNode * node = ROOT;
        int i=0;
        for (; i<searchWord.length(); i++) {
            char & c = searchWord[i];
            int ci = c - 'a';
            if (node->children[ci]) {
                dfs(node->children[ci], matches, word);
            }
            if (!matches.empty()) {
                ans.push_back(matches);
                matches.clear();
                node = node->children[ci];
                word += c;
            } else break;
        }
        for (; i<searchWord.length(); i++) ans.push_back(matches);
        return ans;
    }
private:
    TrieNode * ROOT;
    vector<vector<string>> ans;
    void insert(string s)
    {
        TrieNode * node = ROOT;
        for (char c : s) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode(c);
            node = node->children[i];
        }
        node->terminal = true;
    }
    void dfs(TrieNode * root, vector<string> & matches, string word)
    {
        if (matches.size() < 3) {   // at most three product names
            word += root->val;
            if (root->terminal) matches.push_back(word);
            for (auto child : root->children) {
                if (child) dfs(child, matches, word);
            }
        }
    }
};
