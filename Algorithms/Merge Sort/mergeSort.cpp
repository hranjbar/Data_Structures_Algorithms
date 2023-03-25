/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    void merge(vector<int> & nums, int l, int mid, int r){
        vector<int> left, right;
        int ix = l;
        for (; ix <= mid; ix++) left.push_back(nums[ix]);
        for (; ix <= r; ix++) right.push_back(nums[ix]);
        int i=0, j=0, k=l;
        while (i < left.size() && j < right.size()){
            if (left[i] < right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }
        while (i < left.size()) nums[k++] = left[i++];
        while (j < right.size()) nums[k++] = right[j++];
    }
    void mergeSort(vector<int> & nums, int l, int r){
        if (l < r){
            int mid = l + (r - l) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
