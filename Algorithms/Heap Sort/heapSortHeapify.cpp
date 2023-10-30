/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        len = nums.size();
        for (int j = len - 1; j >= 0; j--) sinkOne(nums, j);
        while (len > 0) {
            int num = nums[0];
            pop(nums);
            nums[len] = num;
        }
        return nums;
    }
private:
    // implement max heap
    int len;
    void sinkTop(vector<int>& nums)
    {
        int i = 0;
        while (i < len) {
            int l = 2 * i + 1, r = 2 * i + 2;
            int bigger;
            if (l < len && r < len) {
                if (nums[l] > nums[r]) bigger = l;
                else bigger = r;
            } else if (l < len) {
                bigger = l;
            } else if (r < len) {
                bigger = r;
            } else break;
            if (nums[bigger] > nums[i]) {
                swap(nums[bigger], nums[i]);
                i = bigger;
            } else break;
        }
    }
    void sinkOne(vector<int>& nums, int i)
    {
        while (i < len) {
            int l = 2 * i + 1, r = 2 * i + 2;
            int bigger;
            if (l < len && r < len) {
                if (nums[l] > nums[r]) bigger = l;
                else bigger = r;
            } else if (l < len) {
                bigger = l;
            } else if (r < len) {
                bigger = r;
            } else break;
            if (nums[bigger] > nums[i]) {
                swap(nums[bigger], nums[i]);
                i = bigger;
            } else break;
        }
    }
    void pop(vector<int>& nums)
    {
        nums[0] = nums[len - 1];
        len--;
        sinkTop(nums);
    }
    // void swim(vector<int>& nums)
    // {
    //     int i = len - 1;
    //     while (i >= 0) {
    //         int root = (i - 1) / 2;
    //         if (nums[i] > nums[root]) {
    //             swap(nums[i], nums[root]);
    //             i = root;
    //         } else break;
    //     }
    // }
    // void insert(int num, vector<int>& nums)
    // {
    //     nums.push_back(num);
    //     len++;
    //     swim(nums);
    // }
};
