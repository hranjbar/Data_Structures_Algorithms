/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        target_ = target;
        sort(candidates.begin(), candidates.end());
        bt(candidates, 0, 0, {});
        return combs_;
    }
    private:
    vector<vector<int>> combs_;
    int target_;
    void bt(vector<int>& nums, int idx, int sum, vector<int> ss)
    {
        if (idx < nums.size() and sum < target_){

            // 1. skip current
            int cur = nums[idx], j = idx;
            while (j < nums.size() and nums[j] == cur) j++;
            bt(nums, j, sum, ss);   // go to a new distinct one
            
            // 2. use then go to next
            ss.push_back(nums[idx]);
            bt(nums, idx + 1, sum + nums[idx], ss);
            
        }
        else {
            if (sum == target_) combs_.push_back(ss);
        }
    }
};
