from typing import List


class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        N = len(nums)
        total_sum = sum(nums)
        min_diff = 1e18

        def backtrack(curr, length, curr_sum):
            nonlocal N, min_diff, total_sum

            if curr >= N or length + (N-curr) < N//2:
                return

            if length >= N//2:
                min_diff = min(min_diff, abs(total_sum-2*curr_sum))
                return

            backtrack(curr+1, length+1, curr_sum+nums[curr])
            backtrack(curr+1, length, curr_sum)

        backtrack(0, 0, 0)

        return min_diff
