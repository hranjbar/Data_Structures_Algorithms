"""
Given an integer n, return the number of prime numbers that are strictly less than n.
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:
Input: n = 0
Output: 0
Example 3:
Input: n = 1
Output: 0
Constraints:
0 <= n <= 5 * 106
Method: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
"""

class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        nums = ["*"] * n
        nums[0] = nums[1] = "-"
        count=1
        p=2
        while True:
            np=p
            while np < n:
                nums[np] = "-"
                np += p
            ix=p+1
            while ix<n:
                if nums[ix] == "*":
                    p=ix
                    count+=1
                    break
                ix+=1
            if ix==n:
                break
        return count
