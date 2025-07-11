/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n))
time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 1. Heapify O(n log n)
        for (int i=nums.size()-1; i>=0; i--) sink(nums, i, nums.size()); // note end

        // 2. in-place sorting O(n log n)
        for (int i=nums.size()-1; i>=0; i--){
            swap(nums[0], nums[i]); // ascending order
            sink(nums, 0, i);   // note end
        }        
        return nums;
    }
    private:

    // max-heap sink
    void sink(vector<int>& nums, int st, int end)
    {
        int i = st;
        while (i < end) {
            int l = 2 * i + 1, r = 2 * i + 2;
            int bigger;
            if (l < end && r < end) {
                if (nums[l] > nums[r]) bigger = l;
                else bigger = r;
            } else if (l < end) {
                bigger = l;
            } else if (r < end) {
                bigger = r;
            } else break;
            if (nums[bigger] > nums[i]) {
                swap(nums[bigger], nums[i]);
                i = bigger;
            } else break;
        }
    }
};
