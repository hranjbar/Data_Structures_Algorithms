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

        // build adjacency matrix
        vector<vector<int>> adj(n, vector<int>(n, -1));  // -1: no edge
        for (vector<int>& time : times){
            adj[time[0] - 1][time[1] - 1] = time[2];
        }

        // Dijkstra's algorithm
        // 1. nodes distances array
        vector<int> shortest_delays(n, INT_MAX);
        shortest_delays[k - 1] = 0; // 0: destination node is k-th node

        // 2. min-heap loop
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k - 1});   // start with destination node
        while (!minHeap.empty()){
            auto [from_delay, from] = minHeap.top();
            minHeap.pop();
            for (int to = 0; to < n; to++){
                int& edge = adj[from][to];
                if (edge > -1){
                    int& to_delay = shortest_delays[to];
                    if (from_delay + edge < to_delay){
                        to_delay = from_delay + edge;
                        minHeap.push({to_delay, to});
                    }
                }
            }
        }

        // time it takes for 'all' the nodes means wait for the slowest 
        // node i.e. maximum of elements of shortest delays
        // return -1 if any node is not accessible i.e. has INT_MAX delay
        int ans = *max_element(shortest_delays.begin(), shortest_delays.end());
        return ans < INT_MAX ? ans : -1;

    }
};
