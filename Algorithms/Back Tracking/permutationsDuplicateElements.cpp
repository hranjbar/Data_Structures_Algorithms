/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

class Solution {
    vector<vector<int>> ans;
    void bt(vector<int> a, int l = 0){
        if (l == a.size() - 1) ans.push_back(a);
        for (int i = l; i < a.size(); i++){
            if (i > l && a[i] == a[l]) continue;
            else {
                swap(a[i], a[l]);
                bt(a, l+1);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bt(nums);
        return ans;
    }
};
