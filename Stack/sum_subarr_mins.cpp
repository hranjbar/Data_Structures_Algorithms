/*
Given an array of integers arr, find the sum of min(b), where b ranges over 
every (contiguous) subarray of arr. Since the answer may be large, return the 
answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444

Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,-1), right(n,n);
        stack<int> st;
        for (int i=0; i<n; i++) {
            while (!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            if (!st.empty()) left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() and arr[st.top()]>arr[i]) st.pop();
            if (!st.empty()) right[i]=st.top();
            st.push(i);
        }
        int k = 7 + 1'000'000'000;
        long ans=0;
        for (int i=0; i<n; i++) {
            ans += (long)(i-left[i]) * (long)(right[i]-i) * (long)arr[i];
            ans %= k;
        }
        return ans;
    }
};

/*[solution explanation](https://www.youtube.com/watch?v=XmFLB3dQ_WA&t=694s)*/
