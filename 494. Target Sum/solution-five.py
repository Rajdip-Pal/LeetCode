from typing import List
from collections import defaultdict


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        sums: int = sum(nums)
        n: int = len(nums)
        dp: List[defaultdict[int, int]] = [
            defaultdict(int) for _ in range(n+1)]

        dp[0][0] = 1  # Base case: one way to reach sum 0 with 0 elements

        for i in range(n):
            for current_sum, count in dp[i].items():
                dp[i + 1][current_sum + nums[i]] += count
                dp[i + 1][current_sum - nums[i]] += count

        return dp[n][target]


'''

# Time Complexity: O(n * m) where n is the length of nums and m is the range of possible sums (from -sum(nums) to sum(nums)).
# Space Complexity: O(n * m) for the dp table.

    Efficiently handles larger inputs without TLE due to dynamic programming approach.

'''
