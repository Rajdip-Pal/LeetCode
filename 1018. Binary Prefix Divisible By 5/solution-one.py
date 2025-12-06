from typing import List


class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        x: int = 0
        res: List[bool] = []

        for i in nums:
            x = (x << 1) | i
            res.append(True if x % 5 == 0 else False)

        return res
