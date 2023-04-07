/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> ans;
    void bk(vector<int> & nums, int l = 0, vector<int> subset = {}){
        ans.push_back(subset);
        for (int i = l ; i < nums.size() ; i++){
            if (i > l && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            bk(nums, i + 1, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bk(nums);
        return ans;
    }
};
