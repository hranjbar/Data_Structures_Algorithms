/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // creating longest prefix suffix vector (LPS) which is 1st step of KMP algorithm
        vector<int> lps(s.length());
        int j = 0, i = 1;
        while (i < lps.size()) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else {
                if (j == 0) lps[i++] = 0;
                else j = lps[j - 1]; // modified to adapt to solution
            }
        }        
        // LPS should be something like [0,0,0,1,2,3,4,5,6]
        // last element shows length of lonest prefix that is a suffix too, is "len"
        // now the length of repeating substring is s.length() - "len" 
        // so one should just check that s.length() - "len" divids s.length()
        // only exception is when s.length() is 1
        int len = lps.back();
        return len > 0 && s.length() % (s.length() - len) == 0;
    }
};
