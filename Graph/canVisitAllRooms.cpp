/*
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. 
However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, 
and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n(rooms.size());
        unordered_set<int> locked;
        for (int i=1; i<n; i++) locked.insert(i);
        queue<int> keys;
        for (int key : rooms[0]) keys.push(key);
        while (!keys.empty()){
            int key = keys.front();
            keys.pop();
            if (locked.count(key)){
                locked.erase(key);
                for (int jey : rooms[key]) keys.push(jey);
            }
        }
        return locked.empty();
    }
};
