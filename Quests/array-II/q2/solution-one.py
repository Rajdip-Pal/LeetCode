from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        num_range: List[int] = [0 for _ in range(100)]
        num_set: List[int] = list(set(nums))

        for i in range(len(num_set)):
            num_range[num_set[i]] = i

        res: List[int] = []

        for i in nums:
            res.append(num_range[i])

        return res
