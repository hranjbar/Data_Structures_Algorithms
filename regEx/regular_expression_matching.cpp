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
        m = s.length(), n = p.length();
        return bt(0, 0, s, p);
    }
private:
    int m, n;
    unordered_map<int, int> cache;
    bool bt(int i, int j, string& s, string& p)
    {
        if (i>=m && j>=n) return true;
        if (j>=n) return false;
        int ix=j + i*n;
        if (cache.count(ix)) return cache[ix];
        bool match = false;
        if (i<m && (s[i]==p[j] || p[j]=='.')) match = true;
        // first handle '*'
        if (j+1<n && p[j+1]=='*') {
            cache[ix] = (match && bt(i+1, j, s, p)) || bt(i, j+2, s, p);
            return cache[ix];
            // bt(i+1, j) means add p[j]
            // bt(i, j+2) means don't add it
            // obviously you add only if s[i] matches p[j]
        }
        if (match) {
            cache[ix] = bt(i+1, j+1, s, p);
            return cache[ix];
        }
        cache[ix] = false;
        return cache[ix];
    }
};
