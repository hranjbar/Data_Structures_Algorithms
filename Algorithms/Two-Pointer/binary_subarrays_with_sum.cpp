/*
Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 
Constraints:
1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
private:
    int atMost(vector<int>& nums, int target)
    {
        int l=0,r=0,curSum=0,count=0;
        for (; r<nums.size(); r++) {
            curSum += nums[r];
            while (l<=r and curSum>target) {
                curSum -= nums[l++];
            }
            count += r-l+1;
        }
        return count;
    }
};
