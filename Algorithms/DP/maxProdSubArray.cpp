/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

lass Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmin = 1, curmax = 1, ans = -10, temp;    // ans = -10 because -10 <= nums[i] <= 10
        for (int & n : nums) {
            temp = curmin;
            curmin = min(n, min(n * curmin, n * curmax));
            curmax = max(n, max(n * temp, n * curmax));
            if (curmax > ans) ans = curmax;
        }
        return ans;
    }
};
/*
The idea for the above solution is Dynamic Programming. We keep track of product minimum and product maximum of the 
growing array. At each step, the new product maximum is the maximum between three values: 
1 - new elemen
2 - new element x maximum product
3 - new element x minimum product
and the similarly the new product minimum is the minimum between three values:
1 - new elemen
2 - new element x maximum product
3 - new element x minimum product
The overall maximum product is updated at each step if the new maximum product is greater than it.
*/
