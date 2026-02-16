from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        total_distance = 0

        for i in range(32):
            ones = 0
            for num in nums:
                ones += (num >> i) & 1
            total_distance += ones * (len(nums)-ones)

        return total_distance
