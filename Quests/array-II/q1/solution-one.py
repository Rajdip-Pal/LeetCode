from typing import List
from collections import Counter


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        res: List[int] = [0, 0]
        counts: Counter[int] = Counter(nums)

        for i in range(1, len(nums)+1):
            if not counts[i]:
                res[-1] = i
            elif counts[i] > 1:
                res[0] = i

        return res
