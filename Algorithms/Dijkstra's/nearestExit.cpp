/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

Example 1:


Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:


Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:


Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
 

Constraints:

maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        typedef pair<int, pair<int, int>> T;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1},{0,-1}};
        vector<vector<int>> dist_map(m, vector<int>(n, INT_MAX));
        dist_map[entrance[0]][entrance[1]] = 0;
        maze[entrance[0]][entrance[1]] = '+'; // don't forget to visit entrance!
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.push({0, {entrance[0], entrance[1]}});
        while (!min_heap.empty()) {
            T el = min_heap.top();
            min_heap.pop();
            int dist = el.first;
            int i = el.second.first;
            int j = el.second.second;
            // printf("cell = [%i,%i]\n", i, j);
            if (edge(i, j) && maze[i][j] == '.') return dist;
            maze[i][j] = '+';   // visit this cell
            for (auto dir : dirs) {
                int ii = i + dir.first;
                int jj = j + dir.second;
                if (!out(ii, jj) && maze[ii][jj] == '.' && dist_map[ii][jj] > (1 + dist)) {
                    dist_map[ii][jj] = 1 + dist;
                    min_heap.push({dist_map[ii][jj], {ii, jj}});
                }
            }
        }
        return -1;
    }
    int m, n;
    bool out(int& i, int& j){return i < 0 || j < 0 || i >= m || j >= n;}
    bool edge(int& i, int& j){return i == 0 || i == m - 1 || j == 0 || j == n - 1;}
};
