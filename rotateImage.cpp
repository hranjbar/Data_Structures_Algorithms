/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int N = matrix.size(), pass;
        for (int nx = 0; nx < N/2 ; nx++){
            for (int ix = nx; ix < N-nx-1; ix++){
                // pass <- top
                pass = matrix[nx][ix];

                // right <-> pass
                std::swap(matrix[ix][N-1-nx], pass);

                // bottom <-> pass
                std::swap(matrix[N-1-nx][N-1-ix], pass); 
                
                // left <-> pass
                std::swap(matrix[N-1-ix][nx], pass);

                // top <- pass
                matrix[nx][ix] = pass;
            }
        }
    }
};
