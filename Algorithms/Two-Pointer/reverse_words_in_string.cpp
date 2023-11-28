/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated 
by a single space.

Note that s may contain leading or trailing spaces or 
multiple spaces between two words. The returned string 
should only have a single space separating the words. 
Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading 
or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two 
words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=s.length()-1;
        // right trim
        while (j>=0 && s[j]==' ') {
            s.pop_back();
            j--;
        }
        while (i < j) swap(s[i++], s[j--]);
        // cout << s << "." << endl;

        // right trim (but left trim of the original s)
        j=s.length()-1;
        while (j>=0 && s[j]==' ') {
            s.pop_back();
            j--;
        }

        i=0;
        int pos=0, l, r, ll, rr;
        while (i<s.length()) {
            // find begining of word = l
            while (i<s.length() && s[i]==' ') i++; 
            l = i;
            // find end of word = r
            while (i<s.length() && s[i] != ' ') i++; 
            r = i-1;

            // reverse word
            ll = l, rr = r;
            while (ll < rr) swap(s[ll++], s[rr--]);

            // place word at right position
            int k = l;
            while(k<=r) s[pos++] = s[k++];
            s[pos++] = ' ';
        }
        pos--;
        j=s.length()-1;
        while (j>=pos) {
            s.pop_back();
            j--;
        }
        
        return s;
    }
};
