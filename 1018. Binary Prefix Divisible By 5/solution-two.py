from typing import List


class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        x: int = 0
        res: List[bool] = []

        for i in nums:
            x = (x*2 + i) % 5
            res.append(x == 0)

        return res
