/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every 
character in t (including duplicates) is included in the 
window. If there is no such substring, return the 
empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" 
includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', 
return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map, s_map;
        for (char& c : t) t_map[c]++;
        int s_l = s.length(), t_l = t.length();
        int L = 0, R = s_l;
        int l = 0, r = -1;
        while (r < s_l-1) {
            do {
                s_map[s[++r]]++;
            } while (!isSubSet(s_map, t_map) && r < s_l);
            if (r-l < R-L) {L = l; R = r;}
            do {
                s_map[s[l++]]--;
                if (isSubSet(s_map, t_map)) {
                    if (r-l < R-L) {L = l; R = r;}
                } else break;
            } while (r-l+1 >= t_l);
        }
        if (R-L < s_l) return s.substr(L, R-L+1);
        else return "";
    }
private:
    // check if `t` is a substring of any permutation of `s`
    bool isSubSet(unordered_map<char, int>& s_map, unordered_map<char, int>& t_map)
    {
        for (auto& [k, v] : t_map) {
            if (s_map[k] < v) return false;
        }
        return true;
    }
};

/*
Hints: 
Hint 1
Use two pointers to create a window of letters in s, which would have all the characters from t.
Hint 2
Expand the right pointer until all the characters of t are covered.
Hint 3
Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.
Hint 4
Continue expanding the right and left pointers until you reach the end of s.
*/
