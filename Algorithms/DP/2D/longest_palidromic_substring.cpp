/*
Given a string s, return the longest 
palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));
        int l=0, r=0;
        for (int i=0; i<len; i++) {
            dp[i][i] = 1;
            if (i<len-1 && s[i]==s[i+1]) {
                dp[i][i+1]=1;
                l=i; r=i+1;
            }
        }
        for (int i=len-3; i>=0; i--) {
            for (int j=i+2; j<len; j++) {
                if (s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j]=1;
                    if (j-i > r-l) {l=i; r=j;}
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};
