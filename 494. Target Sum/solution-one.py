from typing import List


class Solution:
    def __init__(self):
        self.result: int = 0

    def __calculate(self, nums: List[int], target:  int, index: int, current_sum: int) -> None:
        if index == len(nums):
            if current_sum == target:
                self.result += 1
            return

        self.__calculate(
            nums, target, index + 1, current_sum + nums[index])
        self.__calculate(
            nums, target, index + 1, current_sum - nums[index])

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.__calculate(nums, target, 0, 0)
        return self.result


'''

# Time Complexity: O(2^n) where n is the length of nums. In the worst case, we explore all possible combinations of adding and subtracting each number.
# Space Complexity: O(n) for the recursion stack.

    Time Limit Exceeded on larger inputs due to the exponential time complexity.

'''
