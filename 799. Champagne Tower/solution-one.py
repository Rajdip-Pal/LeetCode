from typing import List


class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        prev = [poured]

        for row in range(1, query_row+1):
            curr = [0] * (row+1)
            for glass in range(row):
                extra_liquid = prev[glass] - 1
                if extra_liquid > 0:
                    curr[glass] += extra_liquid / 2
                    curr[glass+1] += extra_liquid / 2

            prev = curr

        return min(1, prev[query_glass])


ans = Solution()
