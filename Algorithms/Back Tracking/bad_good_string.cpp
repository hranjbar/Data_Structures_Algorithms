/*
You categorize strings into three types: good, bad, or mixed. 
If a string has 3 consecutive vowels or 5 consecutive consonants, 
or both, then it is categorized as bad. Otherwise it is 
categorized as good. Vowels in the English alphabet 
are ["a", "e", "i", "o", "u"] and all other letters are consonants.

The string can also contain the character ?, which can be replaced
by either a vowel or a consonant. This means that the string "?aa" 
can be bad if ? is a vowel or good if it is a consonant. This kind
of string is categorized as mixed.

Implement a function that takes a string s and returns its 
category: good, bad, or mixed.

Example
For s = "aeu", the output should be
solution(s) = "bad";

For s = "a?u", the output should be
solution(s) = "mixed";

For s = "aba", the output should be
solution(s) = "good".

Input/Output
[execution time limit] 0.5 seconds (cpp)
[memory limit] 1 GB
[input] string s
A string that can contain only lowercase English letters and the character ?.
Guaranteed constraints:
1 ≤ s.length ≤ 50.
[output] string
good, bad or mixed.
*/

string vs = "aeiou";
unordered_set<char> hs(vs.begin(),vs.end());
string solution(string s, int i=0, int c=0, int v=0) {
    if (c==5 || v==3) return "bad";
    if (i==s.length()) return "good";
    char ch=s[i];
    if (ch=='?') {
        string vow = solution(s,i+1,0,v+1); // pick consonant
        string con = solution(s,i+1,c+1,0);   // pick vowel
        return vow == con ? vow : "mixed";
    } else {
        if (hs.count(ch)) return solution(s,i+1,0,v+1);
        else return solution(s,i+1,c+1,0);
    }
}
