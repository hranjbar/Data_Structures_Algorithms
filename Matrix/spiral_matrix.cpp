/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> ans;
    vector<vector<char>> vis;
    vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};   // right,down,left,up
    int m, n;
    bool isValidDirection(int i, int j, int dx)
    {
        dx = dx%4;
        int ii = i + dirs[dx][0];
        int jj = j + dirs[dx][1];
        if (ii>=0 && ii<m && jj>=0 && jj<n && vis[ii][jj]=='*') {
            return true;
        }
        else return false;
    }
    void dfs(vector<vector<int>>& mat, int i=0, int j=-1, int dx=0)
    {
        dx = dx%4;
        int cur_i = i + dirs[dx][0];
        int cur_j = j + dirs[dx][1];
        ans.push_back(mat[cur_i][cur_j]);
        vis[cur_i][cur_j] = '.';
        if (isValidDirection(cur_i,cur_j,dx)) {
            dfs(mat, cur_i, cur_j, dx);   // keep going
        }
        else if (isValidDirection(cur_i,cur_j,dx+1)) {
            dfs(mat, cur_i, cur_j, dx+1);   // turn right
        } else return;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vis.assign(m, vector<char>(n, '*'));
        dfs(matrix);
        return ans;
    }
};
