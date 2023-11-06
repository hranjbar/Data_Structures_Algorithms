/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps = helper(needle);
        int i = 0, j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                if (j == 0) i++;
                else j = lps[j - 1];
            }
        }
        if (j == needle.length()) return i - j;
        else return -1;
    }
private:
    vector<int> helper(string & pattern)
    {
        vector<int> ret(pattern.length());
        int j = 0, i = 1;
        while (i < pattern.length()) {
            if (pattern[i] == pattern[j]) ret[i++] = ++j;
            else {
                if (j == 0) ret[i++] = 0;
                else j = ret[j - 1];
            }
        }
        return ret;
    }
};
