/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution {
public:
    vector<vector<int>> ans;
    void Backtrack(vector<int> & a, int l = 0){
        if (l == a.size()-1) ans.push_back(a);
        for (int i = l; i < a.size(); i++){
            swap(a[i], a[l]);
            Backtrack(a, l+1);
            swap(a[i], a[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        Backtrack(nums);
        return ans;
    }
};
