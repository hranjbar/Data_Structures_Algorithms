/*
Given an array of integers nums sorted in 
non-decreasing order, find the starting 
and ending position of a given target value.
If target is not found in the array, 
return [-1, -1].
You must write an algorithm with O(log n) 
runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums, target);
        if (l == nums.size() or nums[l] != target){
            return {-1, -1};
        }
        int r = upper(nums, target);
        return {l, r - 1};
    }
    private:
    int lower(vector<int>& nums, int k)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r){
            mid = l + (r - l) / 2;
            if (k <= nums[mid]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    int upper(vector<int>& nums, int k)
    {
        int l = 0, r = nums.size(), mid;    // note r's initial value
        while (l < r){
            mid = l + (r - l) / 2;
            if (k < nums[mid]) r = mid;    // note '<' sign
            else l = mid + 1;
        }
        return l;
    }
};

/* C++ STL solution
auto l=lower_bound(nums.begin(), nums.end(), target);
if (l==nums.end() || *l!=target) return {-1, -1};
return {(int)distance(nums.begin(),l), 
        (int)distance(nums.begin(),upper_bound(nums.begin(), nums.end(), target)-1)};
*/
