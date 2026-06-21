from typing import List
from collections import defaultdict


class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        N = len(nums)
        res = 0

        for start in range(N):
            odd = set()
            even = set()

            if res > N - start:
                break

            for end in range(start, N):
                if nums[end] & 1 == 1:
                    odd.add(nums[end])
                else:
                    even.add(nums[end])

                if len(odd) == len(even):
                    res = max(res, end-start+1)

        return res
