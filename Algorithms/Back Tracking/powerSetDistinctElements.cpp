/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        bt(nums, 0, {});
        return pset_;
    }
    private:
    vector<vector<int>> pset_;
    void bt(vector<int>& nums, int idx, vector<int> ss)
    {
        if (idx < nums.size()){

            // 1. skip go to next
            bt(nums, idx + 1, ss);

            // 2. use and go to next
            ss.push_back(nums[idx]);
            bt(nums, idx + 1, ss);

        } 
        else pset_.push_back(ss);
    }
};
