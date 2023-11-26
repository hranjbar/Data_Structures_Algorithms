/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape.
You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board.
Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are
different if and only if there are two 4-directionally adjacent cells
on the board such that exactly one of the tilings has both squares 
occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/

// solution is here: https://www.youtube.com/watch?v=7cijrfUkQzc

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int mod = 1000000007;
        int l3=1, l2=1, l1=2, cur;
        for (int i=3; i<=n; i++) {
            cur = (2 * l1%mod + l3%mod) % mod;
            l3 = l2;
            l2 = l1;
            l1 = cur;
        }
        return cur;
    }
};
