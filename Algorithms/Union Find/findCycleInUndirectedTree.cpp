/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/

class Solution {
public:
    vector<int> parent, rank;
    int Find(int i) {
        if (parent[i] == i) return i;
        else {
            int result = Find(parent[i]);
            parent[i] = result;
            return result;
        }
    }
    void Union(int i, int j){
        int irep = Find(i);
        int jrep = Find(j);
        if (irep != jrep){
            if (rank[irep] < rank[jrep]) parent[irep] = jrep;
            else if (rank[jrep] < rank[irep]) parent[jrep] = irep;
            else {
                parent[irep] = jrep;
                rank[jrep]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.assign(edges.size() + 1, 0);
        rank.assign(edges.size() + 1, 0);
        for (int i=1; i <= edges.size(); i++) parent[i] = i;
        for (auto e : edges){
            if (Find(e[0]) != Find(e[1])) Union(e[0], e[1]);
            else return e;
        }
        return {};
    }
};
