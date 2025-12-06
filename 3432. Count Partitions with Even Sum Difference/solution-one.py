from typing import List


class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        res: int = 0

        prefix_sum: List[int] = []
        suffix_sum: List[int] = []

        for num in nums:
            if not prefix_sum:
                prefix_sum.append(num)
            else:
                prefix_sum.append(prefix_sum[-1] + num)

        for num in reversed(nums):
            if not suffix_sum:
                suffix_sum.append(num)
            else:
                suffix_sum.append(suffix_sum[-1] + num)

        suffix_sum.reverse()

        for i in range(len(nums)-1):
            if (prefix_sum[i] - suffix_sum[(i + 1)]) % 2 == 0:
                res += 1

        return res
