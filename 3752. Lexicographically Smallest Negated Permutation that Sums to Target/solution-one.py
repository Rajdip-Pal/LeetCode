from typing import List


class Solution:
    def lexSmallestNegatedPerm(self, n: int, target: int) -> List[int]:
        maximum_sum = n*(n+1)//2
        if target > maximum_sum:
            return []
