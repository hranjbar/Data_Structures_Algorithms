/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') 
and walls (represented as '+'). You are also given the entrance of the maze, 
where entrance = [entrancerow, entrancecol] denotes the row and column of the cell 
you are initially standing at.
In one step, you can move one cell up, down, left, or right. You cannot step into a 
cell with a wall, and you cannot step outside the maze. Your goal is to find the 
nearest exit from the entrance. An exit is defined as an empty cell that is at the 
border of the maze. The entrance does not count as an exit.
Return the number of steps in the shortest path from the entrance to the nearest exit, 
or -1 if no such path exists.
 
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
    using T = pair<int, int>;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze.front().size();
        array<T, 4> dirs = {{{1,0}, {-1,0}, {0,1}, {0,-1}}};
        T entr{entrance[0], entrance[1]};

        // Dijkstra's algorithm
        // 1. shortest paths matrix
        vector<vector<int>> shortest_paths(m, vector<int>(n, INT_MAX));
        shortest_paths[entr.first][entr.second] = 0;

        // 2. min_heap loop
        using R = pair<int, T>;
        priority_queue<R, vector<R>, greater<R>> min_heap;
        min_heap.push({0, entr});
        int ans = INT_MAX;
        while (not min_heap.empty()){
            auto [from_dist, from_pos] = min_heap.top();
            min_heap.pop();
            // auto& [from_row, from_col] = from_pos;
            for (auto& dir : dirs){
                T to{dir.first + from_pos.first, dir.second + from_pos.second};
                if (isIn(to) and maze[to.first][to.second] == '.'){
                    int& to_dist = shortest_paths[to.first][to.second];
                    if (from_dist + 1 < to_dist){
                        to_dist = from_dist + 1;
                        min_heap.push({to_dist, to});
                        if (isBorder(to) and to != entr){ // exit can't be entrance
                            ans = min(ans, to_dist);
                        }
                    }
                }
            }
        }
        return ans < INT_MAX ? ans : -1;
    }
    private:
    int m, n;
    bool isIn(T& cell)
    {
        return cell.first >= 0 and cell.first < m and 
            cell.second >= 0 and cell.second < n;
    }
    bool isBorder(T& cell)
    {
        return cell.first == 0 or cell.first == m - 1 or
            cell.second == 0 or cell.second == n - 1;
    }
};
