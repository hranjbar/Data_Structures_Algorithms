/*
Given an unsorted integer array nums. 
Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and 
uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
  
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
  
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool hasone = false;
        for (int& num : nums) {
            if (num==1) hasone=true;
            else if (num<=0 || num>n) num=1;
        }
        if (!hasone) return 1;

        for (int& num : nums) {
            int val = abs(num);
            if (val==n) nums[0] = -nums[0];
            else nums[val] = 0-abs(nums[val]);
        }
        
        for (int i=1; i<n; i++) {
            if (nums[i]>0) {
                return i;
            }
        }
        return nums[0]>0 ? n : n+1;
    }
};

/*
Algorithm
Initialize a variable n to the length of nums, and a boolean contains1 to false.

Traverse nums, check whether 1 occurs, and replace negative numbers, zeros, 
and numbers larger than n with 1. For each element in nums:

If the element equals 1, set contains1 to true.
If the element is less than or equal to 0 or greater than n, replace it with 1.
If the original nums array does not contain 1, return 1.

Traverse nums using a for loop from i equals 0 to n. When value is encountered, 
flip the sign of the number at index value to negative to indicate that it is 
present in the array. Use absolute value to prevent duplicate occurrences of 
value from flipping the sign back to positive.

Set an integer value to the absolute value of nums[i].
If value equals n, we use index 0 to save information about the presence of the 
number n since index n is not available. Set nums[0] to the negative of the 
absolute value of nums[0].
Otherwise, we use index value to store information about the presence of the 
number value. Set nums[value] to the negative of the absolute value of 
nums[value].
Find the smallest missing positive number:
Iterate through the integers 1 to n using iterator i. If nums[i] is positive, 
return i.
If nums[0] is greater than 0 return n.
If nums contains all elements 1 to n, return n + 1 as the smallest missing 
positive number.
*/
