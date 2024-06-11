/*
Given a non-negative integer x, return the square root 
of x rounded down to the nearest integer. The returned integer 
should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we 
round it down to the nearest integer, 2 is returned.

Constraints:
0 <= x <= 0x1<<31 - 1
*/

int mySqrt(int x) {
    if (x < 2) return x;
    int l = 0, r = x, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (x / mid < mid) r = mid;
        else l = mid + 1;
    }   // it's like C++ std::upper_bound()
    return l - 1;
}

/*
Notes: 
1 - x/mid<mid instead of x<mid*mid to avoid signed integer overflow
2 - above implementation is like C++ std::upper_bound() and that's
why we return l-1 in the end instead of l
*/
