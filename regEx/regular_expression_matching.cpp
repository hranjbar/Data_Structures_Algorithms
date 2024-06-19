/*
Given an input string s and a pattern p, implement regular expression 
matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. 
Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', 
there will be a previous valid character to match.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        m = s.length(); n = p.length();
        word = s; pat = p;
        return bt(0, 0);
    }
private:
    int m, n;
    string word, pat;
    unordered_map<int,int> memo;
    bool bt(int i, int j)
    {
        // termination
        if (i >= m && j >= n) return true;
        if (j >= n) return false;

        // lexicographical indexing to avoid default constructor
        // of unordered_map<pair<int,int>,int>
        int ix = j + i * n; 

        // memoization
        if (memo.count(ix)) return memo[ix];

        bool matched = false;
        if (i < m && (word[i] == pat[j] || pat[j] == '.')) matched = true;

        // handle '*' and recursion
        if (j < n - 1 && pat[j + 1] == '*') {
            memo[ix] = (matched && bt(i + 1, j)) ||
                            bt(i, j + 2);
            return memo[ix];
        }

        // matched and recursion
        if (matched) {
            memo[ix] = bt(i + 1, j + 1);
            return memo[ix];
        }

        // when not matched
        memo[ix] = false;
        return false;
    }
};
