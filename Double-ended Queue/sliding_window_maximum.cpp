/*
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the 
window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
Example 2:
Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int mx = INT_MIN;
        vector<int> ans;
        int i = 0;
        for (; i<k; i++) {
            while (!q.empty() && nums[i] > q.back()) q.pop_back();
            if (q.empty()) mx = nums[i];
            q.push_back(nums[i]);
        }
        ans.push_back(mx);
        for (; i<nums.size(); i++) {
            if (nums[i - k] == mx) {
                q.pop_front();
                mx = q.front();
            }
            while (!q.empty() && nums[i] > q.back()) q.pop_back();
            if (q.empty()) mx = nums[i];
            q.push_back(nums[i]);
            ans.push_back(mx);
        }
        return ans;
    }
};

/*
--Intuition
The solution is in the hints. Read the hints again and try to solve it yourself, if couldn't, come back here and read the rest.
--Approach
maintain a double-ended queue, std::deque in C++, named in this solution as q
also maintain a mx elment to add to ans
for the first k elments of nums, if nums[i] is larger than the tail of q, keep removing tail and replacing it with nums[i] until tail is not smaller than nums[i] (that's why in the hints, it's noted that the length of the queue needs not be k)
at this point mx is the first elment of ans
for the remaining elments of nums, first check nums[i-k], if it's equal to mx, remove it from head of q and update mx with q's head.
then, repeat what you did in step 3.
add mx to ans
--Complexity
-Time complexity:
O(N) where N is length of nums
-Space complexity:
O(N)
*/
