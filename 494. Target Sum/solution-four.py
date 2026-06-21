from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        sums: int = sum(nums)

        if -sums > target or target > sums:
            return 0

        n: int = len(nums)
        dp: List[List[int]] = [[float('-inf')] * (2 * sums + 1)
                               for _ in range(n+1)]

        dp[0][sums] = 1  # Base case: one way to reach sum 0 with 0 elements

        for i in range(n):
            for j in range(-sums, sums + 1):
                if dp[i][j + sums] != float('-inf'):
                    if dp[i + 1][j + nums[i] + sums] != float('-inf'):
                        dp[i + 1][j + nums[i] + sums] += dp[i][j + sums]
                    else:
                        dp[i + 1][j + nums[i] + sums] = dp[i][j + sums]
                    if dp[i + 1][j - nums[i] + sums] != float('-inf'):
                        dp[i + 1][j - nums[i] + sums] += dp[i][j + sums]
                    else:
                        dp[i + 1][j - nums[i] + sums] = dp[i][j + sums]

        return dp[n][target + sums] if dp[n][target + sums] != float('-inf') else 0
