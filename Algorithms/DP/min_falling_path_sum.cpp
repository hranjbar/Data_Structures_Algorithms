/*
Given an n x n array of integers matrix, return the minimum sum of any 
falling path through matrix.A falling path starts at any element in 
the first row and chooses the element in the next row that is either 
directly below or diagonally left/right. Specifically, the next 
element from position (row, col) will be (row + 1, col - 1), 
(row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 
Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),a,b,c;
        for (int row=n-2; row>=0; row--) {
            for (int col=0; col<n; col++) {
                b=matrix[row+1][col];
                if(col>0) a=matrix[row+1][col-1];
                else a=INT_MAX;
                if(col<n-1) c=matrix[row+1][col+1];
                else c=INT_MAX;
                matrix[row][col] += min(a,min(b,c));
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
