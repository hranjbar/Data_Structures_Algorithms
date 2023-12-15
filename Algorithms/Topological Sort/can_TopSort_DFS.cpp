/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have
finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
public:
    vector<int> sorted;
    unordered_set<int> vis;
    bool dfs(int cur, vector<vector<int>>& adj)
    {
        if (sorted[cur]) return true;
        if (vis.count(cur)) return false;
        
        // recursion
        vis.insert(cur);
        for (int to : adj[cur]) {
            if (!dfs(to, adj)) return false;
        }
        vis.erase(cur);
        
        sorted[cur]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto p : prerequisites) adj[p[0]].push_back(p[1]);
        sorted.assign(numCourses, 0);
        for (int c=0; c<numCourses; c++) {
            if (!dfs(c, adj)) return false;
        }
        return true;
    }
};
