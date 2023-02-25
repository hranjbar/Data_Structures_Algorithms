/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
n = 2 -> matrix = {{1, 2}, {4, 3}}
n = 3 -> matrix = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}
etc
*/

class Solution {
public:
    void insert(vector<vector<int>> & A, vector<vector<int>> a){
        int n = a.size();
        for (int ix=0; ix<n; ix++) for (int jx=0; jx<n; jx++) A[ix+1][jx+1] = a[ix][jx];
    }
    vector<vector<int>> helper(int nDim, int st){
        if (nDim == 1) return {{st}};
        vector<vector<int>> ans;
        for (int ix=0; ix<nDim; ix++) ans.push_back(std::vector<int>(nDim, 0));
        int val = st;
        for (int jx=0; jx<nDim; jx++, val++) ans[0][jx] = val;
        for (int ix=1; ix<nDim; ix++, val++) ans[ix][nDim-1] = val;
        for (int jx=nDim-2; jx>=0; jx--, val++) ans[nDim-1][jx] = val;
        for (int ix=nDim-2; ix>0; ix--, val++) ans[ix][0] = val;
        if (nDim>2) insert(ans, helper(nDim-2, val));
        return ans;
    }
    vector<vector<int>> generateMatrix(int n) {
        return helper(n, 1);
    }
};
