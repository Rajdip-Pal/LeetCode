from typing import List
from collections import Counter


class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        res: int = 0
        count: Counter[int, int] = Counter(nums)

        keys: List[int] = list(count.keys())

        for i in range(len(keys)):
            for j in range(i + 1, len(keys)):
                for k in range(j + 1, len(keys)):
                    res += count[keys[i]] * count[keys[j]] * count[keys[k]]

        return res
