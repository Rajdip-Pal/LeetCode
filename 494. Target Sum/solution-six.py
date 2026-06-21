from typing import List
from collections import defaultdict


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n: int = len(nums)
        dp: defaultdict[int, int] = defaultdict(int)

        dp[0] = 1  # Base case: one way to reach sum 0 with 0 elements

        for i in range(n):
            nextDp: defaultdict[int, int] = defaultdict(int)
            for current_sum, count in dp.items():
                nextDp[current_sum + nums[i]] += count
                nextDp[current_sum - nums[i]] += count
            dp = nextDp

        return dp[target]


'''

# Time Complexity: O(n * m) where n is the length of nums and m is the range of possible sums (from -sum(nums) to sum(nums)).
# Space Complexity: O(m) for the dp dictionary.

    Efficiently handles larger inputs without TLE due to dynamic programming approach.

'''
