from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res: int = 0

        for row in grid:
            for num in row:
                if num < 0:
                    res += 1

        return res
