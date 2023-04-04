/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

class Solution {
public:
    bool topSortDFS(int i, vector<vector<int>> & adj, vector<int> & vis, stack<int> & st, unordered_set<int> & hash){
        if (hash.count(i)) return false;    // has cycle
        if (vis[i]) return true;
        vis[i] = 1;
        hash.insert(i);
        for (int j : adj[i]) {
            if (!topSortDFS(j, adj, vis, st, hash)) return false;
        }
        hash.erase(i);
        st.push(i);
        return true;
    }
    vector<int> topSort(vector<vector<int>> & adj){
        int n = adj.size();
        stack<int> st;
        vector<int> vis(n, 0);
        unordered_set<int> hash;
        for (int i = 0; i < n; i++){
            if (!topSortDFS(i, adj, vis, st, hash)) return {};
        }
        vector<int> ret;
        while (!st.empty()) {ret.push_back(st.top()); st.pop();}
        return ret;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>({}));
        for (auto uv : prerequisites) adj[uv[1]].push_back(uv[0]);  // b -> a
        return topSort(adj);
    }
};
