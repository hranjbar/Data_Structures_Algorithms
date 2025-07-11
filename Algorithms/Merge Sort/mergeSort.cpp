/*
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) 
time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        partition(nums, 0, nums.size() - 1);
        return nums;
    }
    private:
    void partition(vector<int>& nums, int l, int r)
    {
        if (l < r){
            int mid = l + (r - l) / 2;
            partition(nums, l, mid);
            partition(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }
    void merge(vector<int>& nums, int l, int mid, int r)
    {
        vector<int> left, right;
        int i = l;
        for (; i<=mid; i++) left.push_back(nums[i]);
        for (; i<=r; i++) right.push_back(nums[i]);
        int j = 0, k = 0;
        i = l;
        while (j < left.size() and k < right.size()){
            if (left[j] < right[k]) nums[i++] = left[j++];
            else nums[i++] = right[k++];
        }
        while (j < left.size()) nums[i++] = left[j++];
        while (k < right.size()) nums[i++] = right[k++];
    }
};
