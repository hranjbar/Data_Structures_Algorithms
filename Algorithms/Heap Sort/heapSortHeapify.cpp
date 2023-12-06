/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n))
time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // vector<int> sorted;
        int len = nums.size();
        // for (int& n : nums) insert(n, sorted, len);
        for (int j = len - 1; j >= 0; j--) heapify(nums, j);
        for (int j = nums.size() - 1; j >= 0; j--) {
            int num = pop(nums, len);
            nums[j] = num;
        }
        return nums;
    }
private:
    // implement max heap
    void swim(vector<int>& nums, int& len)
    {
        int i = len - 1;
        while (i >= 0) {
            int root = (i - 1) / 2;
            if (nums[i] > nums[root]) {
                swap(nums[i], nums[root]);
                i = root;
            } else break;
        }
    }
    void sink(vector<int>& nums, int& len)
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
    void heapify(vector<int>& nums, int i)
    {
        int len = nums.size();
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
    void insert(int num, vector<int>& nums, int& len)
    {
        nums.push_back(num);
        len++;
        swim(nums, len);
    }
    int pop(vector<int>& nums, int& len)
    {
        int ret = nums[0];
        nums[0] = nums[len - 1];
        len--;
        sink(nums, len);
        return ret;
    }
};
