from collections import Counter
from typing import List


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        BASE = 10**9 + 7

        cnt = Counter(p[-1] for p in points)

        res = 0
        prefix = 0

        for v in cnt.values():
            if v < 2:
                continue
            x = v * (v - 1) // 2
            res = (res + x * prefix) % BASE
            prefix = (prefix + x) % BASE

        return res
