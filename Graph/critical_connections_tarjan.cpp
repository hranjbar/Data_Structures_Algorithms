/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
connections forming a network where connections[i] = [ai, bi] represents a connection 
between servers ai and bi. Any server can reach other servers directly or indirectly 
through the network.
A critical connection is a connection that, if removed, will make some servers unable 
to reach some other server.
Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

class Solution {
public:
    unordered_set<int> vis;
    vector<int> low, disc;
    vector<vector<int>> adj, ans;
    int t;
    void dfs(int cur, int parent)
    {
        low[cur] = disc[cur] = ++t;
        vis.insert(cur);
        for (int to : adj[cur]) {
            if (to == parent) continue;
            if (vis.count(to)) low[cur] = min(low[cur], disc[to]);
            else {
                dfs(to, cur);
                low[cur] = min(low[cur], low[to]);
                if (disc[cur] < low[to]) ans.push_back({cur, to});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n,{});
        for (auto con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        low.assign(n, -1);
        disc.assign(n, -1);
        t=0;
        for (int i=0; i<n; i++) {
            if (vis.count(i)==0) dfs(i, -1);
        }
        return ans;
    }
};
