/*
In English, we have a concept called root, which can be followed by some other 
word to form another longer word - let's call this word derivative. 
For example, when the root "help" is followed by the word "ful", we can form 
a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words
separated by spaces, replace all the derivatives in the sentence with the root
forming it. If a derivative can be replaced by more than one root, replace it 
with the root that has the shortest length.
Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled 
by the battery"
Output: "the cat was rat by the bat"

Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

class Solution {
struct TrieNode {
    char c;
    bool terminal;
    vector<TrieNode*> kids;
    TrieNode(char val) : c(val), terminal(false), kids(26, nullptr) {}
};
void split(string& s, vector<string>& out)
{
    int i = 0;
    while (i < s.length()) {
        string word = "";
        while (i < s.length() && !isspace(s[i])) {
            word += s[i];
            i++;
        }
        out.push_back(word);
        i++;
    }
}
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode('\0');
        // insert
        for (string& word : dictionary) {
            TrieNode * cur = root;
            for (char& c : word) {
                int ci = c - 'a';
                if (cur->kids[ci] == nullptr) cur->kids[ci] = new TrieNode(c);
                cur = cur->kids[ci];
            }
            cur->terminal = true;
        }
        vector<string> words, ans_array;
        split(sentence, words);
        for (string& word : words) {
            // serach
            bool found = false;
            string rt;
            TrieNode * cur = root;
            for (char& c : word) {
                int ci = c - 'a';
                if (cur->kids[ci] == nullptr) break;
                cur = cur->kids[ci];
                rt += cur->c;
                if (cur->terminal) {found = true; break;}
            }
            if (found) ans_array.push_back(rt);
            else ans_array.push_back(word);
        }
        string ans;
        for (int i = 0; i < ans_array.size() - 1; i++) ans += ans_array[i] + " ";
        ans += ans_array.back();
        return ans;

    }
};
