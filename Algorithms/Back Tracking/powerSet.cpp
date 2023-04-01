/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> ans;
    void bk(vector<int> & nums, int & k, int l = 0, vector<int> subset = {}){
        if (k == subset.size()) ans.push_back(subset);
        else {
            for (int i = l; i < nums.size(); i++){
                subset.push_back(nums[i]);
                bk(nums, k, i + 1, subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int k=0; k <= nums.size(); k++) bk(nums, k);
        return ans;
    }
};
