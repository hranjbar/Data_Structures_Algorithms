/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
  There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise./*
*/

class Trie {
public:
    struct TrieNode {
        char val;
        bool isTerminal;
        vector<TrieNode *> children;
        TrieNode () {val = '\0'; isTerminal = false; children = vector<TrieNode *>(26, nullptr);}
        TrieNode (char c) {val = c; isTerminal = false; children = vector<TrieNode *>(26, nullptr);}
    };
    TrieNode * root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * node = root;
        for (char & c : word){
            int ci = c - 97;    // ci in {0, 1, ..., 25}
            if (!node->children[ci]) node->children[ci] = new TrieNode(c);
            node = node->children[ci];
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode * node = root;
        int ci;
        for (const char c : word){
            ci = c - 97;
            if (!node->children[ci]) return false;
            node = node->children[ci];
        }
        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode * node = root;
        int ci;
        for (const char c : prefix){
            ci = c - 97;
            if (!node->children[ci]) return false;
            node = node->children[ci];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
