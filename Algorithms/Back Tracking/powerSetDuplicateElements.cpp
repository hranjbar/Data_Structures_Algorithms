/*
Given an integer array nums that may contain duplicates, 
return all possible subsets (the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bt(nums, 0, {});
        return pset_;
    }
    vector<vector<int>> pset_;
    void bt(vector<int>& nums, int idx, vector<int> ss)
    {
        if (idx < nums.size()){

            // 1. Skip to next distinct num
            int cur = nums[idx], j = idx;
            while (j < nums.size() and cur == nums[j]) j++;
            bt(nums, j, ss);

            // 2. Use and got to next
            ss.push_back(nums[idx]);
            bt(nums, idx + 1, ss);
         
        }
        else pset_.push_back(ss);
    }
};
