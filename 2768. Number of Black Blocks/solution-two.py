from typing import List
from collections import defaultdict


class Solution:
    def countBlackBlocks(self, row: int, col: int, coordinates: List[List[int]]) -> List[int]:
        res = [0] * 5
        total_blocks = (row-1)*(col-1)

        if not coordinates:
            res[0] = total_blocks
            return res

        matrix = defaultdict(int)

        for c in coordinates:
            d = [[0, 0], [0, -1], [-1, 0], [-1, -1]]

            for idx in range(4):
                x_new, y_new = c[0]+d[idx][0], c[1]+d[idx][1]

                if x_new < 0 or y_new < 0:
                    continue

                if x_new >= row-1 or y_new >= col-1:
                    continue

                matrix[(x_new, y_new)] += 1

        for v in matrix.values():
            res[v] += 1

        res[0] = total_blocks - sum(res)

        return res


s = Solution()

print(s.countBlackBlocks(3, 3, [[0, 0]]))
print(s.countBlackBlocks(3, 3, [[0, 0], [1, 1], [0, 2]]))

# Excessive mem usage
