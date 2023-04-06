/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> ans;
    void bk(vector<int> & nums, int l = 0, vector<int> subset = {}){
        ans.push_back(subset);
        for (int i = l; i < nums.size(); i++){
            subset.push_back(nums[i]);
            bk(nums, i + 1, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        bk(nums);
        return ans;
    }
};
