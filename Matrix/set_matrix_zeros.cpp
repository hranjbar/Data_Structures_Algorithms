/*
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 
Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        // use first row to track the columns that will later be set to zero
        // use first colomn to track the rows that will later be set to zero
        
        // scan
        int flag = 0;
        int r0; // since first row and first column will have overlap 
                // in the first elment of matrix, we need an extra variable
                // to store the flag for the first row (or the first column if you wish)
        r0 = ~flag; // just rc0 != flag

        // explore first row
        for (int j=0; j<n; j++) {
            if (matrix[0][j]==0) {
                r0=flag;
                matrix[0][j]=flag;
            }
        }
        // explore rest of the rows
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j]==0) {
                   matrix[i][0]=flag;
                   matrix[0][j]=flag;
                }
            }
        }


        // set to zero
        // you must start from lower right of the matrix 
        // and move back left up!
        // cover the last row
        int i=m-1;
        for (; i>0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (matrix[i][0]==flag || matrix[0][j]==flag) matrix[i][j]=0;
            }
        }
        // cover rest of the rows
        for (int j=n-1; j>=0; j--) {
            if (r0==flag || matrix[0][j]==flag) matrix[i][j]=0;
        }
        
    }
};

/*
use first row to track the columns that will later be set to zero
use first colomn to track the rows that will later be set to zero
since first row and first column will have overlap in the first elment 
of matrix, we need an extra variable r0 to store the flag for the 
first row (or the first column if you wish)
go through each element of matrix and if 0 flag the row's header 
(matrix[i][0]) and column's header (matrix[0][j])
dont' forget to handle the first row separately than the rest of 
the rows due to the over lap explained above.
now it's time to modify the matrix in place.
since we used the first row and first column (and an extra variable) 
to store the flags, we MUST start from the lower right (end) of matrix
and build our way back up toward upper left of matrix
we can handle the first row separtely to avoid extra branching inside 
the j loop.
remember that the flag for the first row is not saved in matrix[0][0], 
it's saved in r0 (3rd bullet point above)
*/
