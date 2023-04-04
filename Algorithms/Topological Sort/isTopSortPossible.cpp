/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

class Solution {
public:
    bool dfs(int i, vector<int> & vis, vector<vector<int>> & adj, unordered_set<int> & hash){
        if (hash.count(i)) return true;
        if (vis[i]) return false;
        vis[i] = 1;
        hash.insert(i);
        for (int j : adj[i]){
            if (dfs(j, vis, adj, hash)) return true;
        }
        hash.erase(i);
        return false;
    }
    bool hasCycle(vector<vector<int>> & adj){
        int n = adj.size();
        vector<int> vis(n, 0);
        unordered_set<int> hash;
        for (int i = 0; i < n; i++){
            if (dfs(i, vis, adj, hash)) return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>({}));
        for (auto req : prerequisites) adj[req[1]].push_back(req[0]); // b -> a
        return !hasCycle(adj);
    }
};
