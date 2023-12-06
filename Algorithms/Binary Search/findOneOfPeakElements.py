'''
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its
index. If the array contains multiple peaks, return the index to any of 
the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element
is always considered to be strictly greater than a neighbor that is 
outside the array.

You must write an algorithm that runs in O(log n) time.
'''

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def lookup(i):
            if 0 <= i < len(nums):
                return nums[i]
            else:
                return -(1 << 31)
        l, r = 0, len(nums)-1
        while l <= r:
            mid = l + (r - l) // 2
            if lookup(mid) > lookup(mid+1) and lookup(mid) > lookup(mid-1):
                return mid
            elif lookup(mid) < lookup(mid-1):
                r = mid-1
            else:
                l = mid+1
        return mid
