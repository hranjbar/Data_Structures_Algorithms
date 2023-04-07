/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

class Solution {
    vector<vector<int>> ans;
    void bt(vector<int> & a, int rem, int ix = 0, vector<int> subset = {}) {
        if (ix == a.size() || rem <= 0) {
            if (rem == 0) ans.push_back(subset);
        }
        else {
            subset.push_back(a[ix]);
            bt(a, rem - a[ix], ix + 1, subset);
            subset.pop_back();
            int cur = a[ix];
            do {ix++;} while (ix < a.size() && a[ix] == cur);
            bt(a, rem, ix, subset);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        bt(candidates, target);
        return ans;
    }
};
