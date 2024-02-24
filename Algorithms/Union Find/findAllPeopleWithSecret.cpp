/*
You are given an integer n indicating there are n people 
numbered from 0 to n - 1. You are also given a 0-indexed 
2D integer array meetings where 
meetings[i] = [xi, yi, timei] indicates that 
person xi and person yi have a meeting at timei. 
A person may attend multiple meetings at the same time. 
Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret 
with a person firstPerson at time 0. This secret is 
then shared every time a meeting takes place with a 
person that has the secret. More formally, for every 
meeting, if a person xi has the secret at timei, 
then they will share the secret with person yi, 
and vice versa.

The secrets are shared instantaneously. That is, 
a person may receive the secret and share it with 
people in other meetings within the same time frame.

Return a list of all the people that have the secret 
after all the meetings have taken place. You may return 
the answer in any order.

Example 1:
Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], 
firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after 
all the meetings.

Example 2:
Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], 
firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the 
secret.
At time 3, person 3 shares the secret with person 0 
and person 1.
Thus, people 0, 1, and 3 know the secret after 
all the meetings.

Example 3:
Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], 
firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, 
and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same
time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after
all the meetings.

Constraints:
2 <= n <= 105
1 <= meetings.length <= 105
meetings[i].length == 3
0 <= xi, yi <= n - 1
xi != yi
1 <= timei <= 105
1 <= firstPerson <= n - 1
*/

class Solution {
public:
    vector<int> parent;
    void dfs(int p, unordered_map<int, vector<int>>& adj, 
unordered_set<int>& vis)
    {
        if (vis.count(p)==0) {
            parent[p]=0;    // let this person know
            vis.insert(p);
            for (int& q : adj[p]) dfs(q, adj, vis);
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, 
int firstPerson) {

        // 1. Construct architecture of partial Union-Find
        for (unsigned i=0; i<n; i++) {parent.push_back(i);} 
      // initially only 0 knows the secret
        parent[firstPerson] = 0;  // 0 is parent of all secret knowers!


        // 2. Take care of simultanous meetings
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){return a[2] < b[2];});
        int m = meetings.size(), mi=0;
        
        while (mi < m) {
            unordered_map<int, vector<int>> adj;    
          // adjacency matrix per group of simultaneous meetings
            int hour=meetings[mi][2];
            while (mi < m and meetings[mi][2]==hour) {  
              // all meetings at the same time
                int &p1=meetings[mi][0], &p2=meetings[mi][1];
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
                mi++;
            }
            // spread secret for all meetings at the same time
            unordered_set<int> vis;
            for (auto& [p, v] : adj) {
                if (vis.count(p)==0 and parent[p]==0) { 
                  // if this knows the secret
                    dfs(p, adj, vis);
                }
            }
        }
        
        // 3. populate
        vector<int> ans;
        for (int p=0; p < n; p++) {
            if (parent[p]==0) ans.push_back(p);
        }
        return ans;
    }
};
