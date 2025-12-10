from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n: int = len(nums)
        possibilities: int = 2 ** n - 1

        result: int = 0

        while possibilities >= 0:
            temp = possibilities
            current_sum: int = 0
            for i in range(n):
                if (temp >> i) & 1:
                    current_sum += nums[i]
                else:
                    current_sum -= nums[i]

            if current_sum == target:
                result += 1

            possibilities -= 1

        return result


'''

# Time Complexity: O(n * 2^n) where n is the length of nums. We iterate through all possible combinations (2^n) and for each combination, we calculate the sum which takes O(n) time.
# Space Complexity: O(1) as we are using a constant amount of extra space.

    Time Limit Exceeded on larger inputs due to the exponential time complexity.

'''
