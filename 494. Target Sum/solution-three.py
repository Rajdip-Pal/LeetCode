from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo: dict[(int, int), int] = {}

        def backtrack(index: int, current_sum: int) -> int:
            if index == len(nums):
                return 1 if current_sum == target else 0

            if (index, current_sum) in memo:
                return memo[(index, current_sum)]

            add = backtrack(index + 1, current_sum + nums[index])
            subtract = backtrack(index + 1, current_sum - nums[index])

            memo[(index, current_sum)] = add + subtract

            return memo[(index, current_sum)]

        return backtrack(0, 0)


'''

# Time Complex
# Space Complexity

    NO TLE atleast

'''
