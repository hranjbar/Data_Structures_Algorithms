/*
Binary Search template.
It's gauranteed to pass all edge cases.
It Searches in the array 'nums' in pursuit of value 'target'.
If target value found, it will return its index in the array, otherwise will return negative one.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        do {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        } while(l <= r);
        return -1;
    }
};
