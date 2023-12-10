/*
Given an integer n, return the number of prime numbers 
that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, 
they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
0 <= n <= 5 * 106
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;  // edge cases
        vector<int> composites(n,0);
        int ans = 0, p = 2; // p is the current prime number
        while (p<n) {
            ans++;
            for (int m=p; m<n; m+=p) composites[m]=1;
            while (p<n && composites[p]) p++;
        }
        return ans;
    }
};
/*solution based on:
Sieve of Eratosthenes
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/
