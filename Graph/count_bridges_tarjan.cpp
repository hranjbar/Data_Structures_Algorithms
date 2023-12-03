/*
Note: Try to solve this task in O(n2) time, where n is a number of 
vertices, since this is what you'll be asked to do during an interview.

Sue is a network administrator who consults for companies that have 
massive Local Area Networks (LANs). The computers are connected together 
with network cables, and Sue has been brought in to evaluate the 
company’s network. The networks are huge, and she wants to ensure 
that no single network cable failure can disconnect the network. 
Any cable that fails that leaves the network in two or more 
disconnected pieces is called a single point of failure.

She labels the different network devices from 0 to n - 1. She keeps 
an n × n matrix connections, where connections[i][j] = 1 if there is 
a network cable directly connecting devices i and j, and 0 otherwise. 
Write a function that takes the matrix of connections, and returns 
the number of cables that are a single point of failure.

Example

For connections = [[0, 1], [1, 0]], the output should be
solution(connections) = 1.
A failure of the cable that connects devices 0 and 1 would leave the
network disconnected.

For connections = [[0, 1, 1], [1, 0, 1], [1, 1, 0]], the output should be
solution(connections) = 0.
No failure of a single network cable would result in the network 
being disconnected.

For connections = [[0, 1, 1, 1, 0, 0], [1, 0, 1, 0, 0, 0], 
[1, 1, 0, 0, 0, 0], [1, 0, 0, 0, 1, 1], [0, 0, 0, 1, 0, 0], 
[0, 0, 0, 1, 0, 0]], the output should be
solution(connections) = 3.
The three cables that are single points of failure are 
connected with device 3:

For connections = [[0, 1, 1, 1, 1], [1, 0, 0, 0, 0], 
[1, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0]], the output should be
solution(connections) = 4.
In this topology, every cable is a single point of failure:
*/

void dfs(int v, vector<vector<int>>& adj, vector<int>& vis, vector<int>& low, vector<int>& tin, int& ans, int& t, int p=-1)
{
    vis[v] = 1;
    low[v] = tin[v] = ++t; 
    for (int to : adj[v]) {
        if (to==p) continue;
        if (vis[to]==1) low[v] = min(low[v], tin[to]);
        else {
            dfs(to, adj, vis, low, tin, ans, t, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) ans++;
        }
    }
}
int solution(vector<vector<int>> connections) {
    int n = connections.size();
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (connections[i][j]==1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0, t = 0;
    vector<int> vis(n);
    vector<int> low(n,-1);
    vector<int> tin(n,-1);
    for (int i=0; i<n; i++) {
        if (vis[i]==0) dfs(i, adj, vis, low, tin, ans, t);
    }
    return ans;
}

// Tarjan's algorithm @ https://www.geeksforgeeks.org/bridge-in-a-graph/
/*
Before heading towards the approach understand which edge is termed as bridge. 
Suppose there exists a edge from u -> v, now after removal of this edge if v 
can’t be reached by any other edges then u -> v edge is bridge. Our approach 
is based on this intuition, so take time and grasp it.

ALGORITHM: –

To implement this algorithm, we need the following data structures –

visited[ ] = to keep track of the visited vertices to implement DFS
disc[ ] = to keep track when for the first time that particular vertex is reached
low[ ] = to keep track of the lowest possible time by which we can reach that 
vertex ‘other than parent’ so that if edge from parent is removed can the 
particular node can be reached other than parent.
We will traverse the graph using DFS traversal but with slight modifications
i.e. while traversing we will keep track of the parent node by which the 
particular node is reached because we will update the 
low[node] = min(low[all it’s adjacent node except parent]) 
hence we need to keep track of the parent.

While traversing adjacent nodes let ‘v’ of a particular 
node let ‘u’ 3 cases arise –

1. v is parent of u then, 

skip that iteration.
2. v is visited then,

update the low of v i.e. low[u] = min( low[u] , disc[v]) 
this arises when a node can be visited by more than one node, 
but low is to keep track of the lowest possible time so we will update it.
3. v is not visited then,

call the DFS to traverse ahead
now update the low[u] = min( low[u], low[v] ) as we 
know v can’t be parent cause we have handled that case first.
now check if ( low[v] > disc[u] ) i.e. the lowest possible 
to time to reach ‘v’ is greater than ‘u’ this means 
we can’t reach ‘v’ without ‘u’ so the edge   u -> v is a bridge.
*/
