/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, 
list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, 
and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto & el : times) {
            int & u = el[0], & v = el[1], & w = el[2];
            adj[u - 1].push_back({v, w});
        }
        
        vector<int> delays(n, INT_MAX);
        typedef pair<int, int> T;   // hint
        priority_queue<T, vector<T>, greater<T>> q;
        q.push({0, k});
        delays[k - 1] = 0;
        unordered_set<int> vis;
        
        while (!q.empty()) {
            auto el = q.top();
            q.pop();
            int d = el.first;
            int u = el.second;
            vis.insert(u);
            for (auto [v, w] : adj[u - 1]) {
                if (vis.count(v) == 0 && delays[v - 1] > w + d) {
                    delays[v - 1] = w + d;
                    q.push({delays[v - 1], v});
                }
            }
        }
        // loop over all delays, all should be finite, pick the max (worst)
        int ans = INT_MIN;
        for (int & delay : delays) {
            if (delay == INT_MAX) return -1;
            if (delay > 0 && delay > ans) ans = delay;
        }
        return ans;
    }
};
