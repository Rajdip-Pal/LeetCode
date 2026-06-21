from typing import List


class Solution:
    def _find_max_index(self, nums: List[int], l: int, r: int) -> int:
        max_idx = l
        for i in range(l + 1, r + 1):
            if nums[i] > nums[max_idx]:
                max_idx = i
        return max_idx

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        l, r = 0, k-1
        res = []

        max_idx = self._find_max_index(nums, l, r)

        while r < len(nums):
            if nums[r] >= nums[max_idx]:
                max_idx = r
            elif max_idx < l:
                max_idx = self._find_max_index(nums, l, r)

            res.append(nums[max_idx])
            l += 1
            r += 1

        return res


# Ends with TLE
