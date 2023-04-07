/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
    vector<vector<int>> ans;
    int t;
    void bt(vector<int> & a, int ix = 0, vector<int> subset = {}, int sum = 0) {
        if (ix == a.size() || sum >= t) {
            if (sum == t) ans.push_back(subset);
        }
        else {
            subset.push_back(a[ix]);
            bt(a, ix, subset, sum + a[ix]);
            subset.pop_back();
            bt(a, ix + 1, subset, sum);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t = target;
        bt(candidates);
        return ans;
    }
};
