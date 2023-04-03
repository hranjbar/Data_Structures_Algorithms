class Solution {
public:
    vector<vector<int>> Adj(vector<vector<int>> & edges, int n){
        vector<vector<int>> ret(n, vector<int>({}));
        for (auto edge : edges) ret[edge[1]].push_back(edge[0]);
        return ret;
    } // return adjacency matrix from edges
    vector<int> topSort(vector<vector<int>> & edges, int n){
        vector<vector<int>> adjacency = Adj(edges, n);
        vector<int> inDeg(n, 0);
        for (auto to : adjacency){
            for (int n : to) inDeg[n]++;
        }
        queue<int> q;
        vector<int> ret;
        for (int node = 0; node < n; node++){
            if (inDeg[node] == 0) {
                q.push(node);
                inDeg[node]--;
            }
        }
        while (!q.empty()){
            int & node = q.front();
            q.pop();
            ret.push_back(node);
            for (int to : adjacency[node]) inDeg[to]--;
            for (int node = 0; node < n; node++){
                if (inDeg[node] == 0){
                    q.push(node);
                    inDeg[node]--;
                }
            }
        }
        return ret;
    }
};
