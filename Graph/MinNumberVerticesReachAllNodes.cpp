/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge 
from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> hash;
        for (int i=0; i<n; i++) hash.insert(i);
        for_each(edges.begin(), edges.end(), [&hash](vector<int> & el){hash.erase(el[1]);});
        return vector<int>(hash.begin(), hash.end());
    }
};
