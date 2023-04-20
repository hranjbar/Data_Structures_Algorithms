/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

class Solution {
    void sink(vector<int> & a, int st, int en) {
        int i = st, l, r;
        while (i < en) {
            l = 2*i + 1;
            r = 2*i + 2;
            if (l < en && r < en) {
                if (a[l] > a[r]) {
                    if (a[l] > a[i]) swap(a[l], a[i]);
                    i = l;
                } else {
                    if (a[r] > a[i]) swap(a[r], a[i]);
                    i = r;
                }
            } else if (l < en) {
                if (a[l] > a[i]) swap(a[l], a[i]);
                i = l;
            } else break;
        }
    }
    int len;
    void heapify(vector<int> & a) {
        len = a.size();
        for (int j = len - 1; j >= 0; j--) sink(a, j, len);
    }
    void pop(vector<int> & heap) {
        len--;
        swap(heap[0], heap[len]);
        sink(heap, 0, len);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapify(nums);
        while (len) pop(nums);
        return nums;
    }
};
