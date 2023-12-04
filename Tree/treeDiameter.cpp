/*
Diameter of a tree is the maximal possible distance between its two vertices.
Find diameter.

The number of vertices in the structure you drew in your notebook.

Guaranteed constraints:
1 ≤ n ≤ 104.

[input] array.array.integer tree

Edges of the tree. tree[i] for each valid i contains two elements 
and represents an edge that connects tree[i][0] and tree[i][1].
It is guaranteed that given graph is a tree, i.e. it is connected 
and has no cycles.

Guaranteed constraints:
tree.length = n - 1,
tree[i].length = 2,
0 ≤ tree[i][j] < n.

[output] integer

tree diameter of the given tree.
*/

int solution(int n, vector<vector<int>> tree) {
    vector<vector<int>> adj(n);
    for (auto edge : tree) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    queue<int> qu;
    qu.push(0);
    vector<int> vis(n);
    int p;
    while (!qu.empty()) {
        p = qu.front();
        qu.pop();
        vis[p]=1;
        for (int to : adj[p]) {
            if (vis[to]==0) qu.push(to);
        }
    }
    int ans=0;
    queue<pair<int, int>> pair_qu;
    pair_qu.push({0, p});
    vis.assign(n,0);
    while (!pair_qu.empty()) {
        pair<int, int> el = pair_qu.front();
        pair_qu.pop();
        int d=el.first, cur=el.second;
        vis[cur]=1;
        ans = max(ans, d);
        for (int to : adj[cur]) {
            if (vis[to]==0) pair_qu.push({d+1,to});
        }
    }
    return ans;
}
