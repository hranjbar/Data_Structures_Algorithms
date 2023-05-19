'''
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
'''

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        i = 1
        count = 0
        while i < n:
            diff = nums[i] - nums[i - 1]
            j = i + 1
            while j < n and nums[j] - nums[j - 1] == diff:
                j += 1
            m = j - i + 1
            if m >= 3:
                count += ((m - 2) * (m - 1)) // 2     #  = 1 + 2 + ... + m - 2 = \sum_{i = 1}^{m - 2}{i}
            i = j
        return count
