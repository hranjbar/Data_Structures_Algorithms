/*
Given an integer array nums and an integer k, 
return the k most frequent elements. You may
return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique 
elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must 
be better than O(n log n), where n is the 
array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;
        for (int& num : nums) hmap[num]++;
        typedef pair<int,int> T;    // {num, freq}
        auto cmp = [](const T& l, const T& r){return l.second > r.second;};
        priority_queue<T, vector<T>, decltype(cmp)> minHeap;
        for (auto& [key, val] : hmap) {
            if (minHeap.size() < k) minHeap.push({key, val});
            else if (val > minHeap.top().second) {
                minHeap.pop();
                minHeap.push({key,val});
            }
        }
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;
    }
};
