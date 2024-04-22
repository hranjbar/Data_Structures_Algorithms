/*
Given two strings needle and haystack, return the index of 
the first occurrence of needle in haystack, or -1 if 
needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", 
so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase 
English characters.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.length());
        kmp(needle, lps);
        int hix=0, nix=0;
        while (hix<haystack.length() && nix<needle.length()){
            if (haystack[hix] == needle[nix]) {hix++; nix++;}
            else {
                if (nix==0) hix++;
                else nix = lps[nix-1];
            }
        }
        if (nix == needle.length()) return hix-nix;
        else return -1;
    }
private:
    void kmp(string& pat, vector<int>& lps)
    {
        int len=0, i=1;
        while (i<pat.length()) {
            if (pat[i]==pat[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len==0) {lps[i]=0; i++;}
                else {len = lps[len-1];}
            }
        }
    }
};
