/*
Given an array of integers nums and an integer k, return the number
of contiguous subarrays where the product of all the elements in
the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not
strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
 
Constraints:
1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 2) return 0;
        int ans = 0;
        for (int l=0, r=0, prod=1; r<nums.size(); r++) {
            prod *= nums[r];
            while(prod >= k) prod /= nums[l++];
            ans += (r - l + 1);
        }
        return ans;
    }
};

/*
The count of such subarrays is determined by the difference 
right - left + 1, which represents the number of subarrays 
that end at right and start at any element between right 
and left, inclusive. In essence, this count encompasses the
subarray consisting solely of the current element itself, 
as well as all possible subarrays extending back to the 
left boundary of the window (left).

Algorithm
Check if k is less than or equal to 1. In this case, no 
subarrays can have a product less than k, so return 0.
Initialize the variables totalCount to 0, to store the 
final count of subarrays with a product less than k, 
and product to 1, representing the product of elements 
within the window (initially empty).
Use two pointers, left and right, to define the sliding 
window. Iterate through the nums array using a for loop 
until right reaches the end.
Inside the loop, multiply the current product by the 
element at the right pointer (nums[right]). This 
effectively includes the new element in the window.
While the current product is greater than or equal to 
k, the window needs to shrink to exclude elements that
make the product exceed k.
Divide the product by the element at the left 
pointer (nums[left]).
Increment left by 1 to move the window one position to 
the right, effectively excluding the leftmost element.
Update the totalCount by adding the number of valid 
subarrays with the current window size, which 
is right - left + 1.
Return the totalCount.
*/
