/*
You are given an n x n 2D matrix representing an image,
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you 
have to modify the input 2D matrix directly. DO NOT 
allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],
[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],
[16,7,10,11]]

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row=0; row<n/2; row++) {
            for (int col=row; col<n-1-row; col++) {
                int pass=matrix[row][col];  // top
                swap(matrix[col][n-1-row],pass);    // right
                swap(matrix[n-1-row][n-1-col],pass);   // bottom
                swap(matrix[n-1-col][row],pass);    // left
                matrix[row][col]=pass;    // top
            }
        }
    }
};
/*
1. for 90-deg clockwise rotation, move:
    top row      -> right column
    right column -> bottom row
    bottom row   -> left column
    left column  -> top row
2. just cover half the rows
3. row after row, column range will
become shorter (inward spiral trajectory)
*/
