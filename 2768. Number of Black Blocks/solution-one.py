from typing import List


class Solution:
    def countBlackBlocks(self, row: int, col: int, coordinates: List[List[int]]) -> List[int]:
        res = [0] * 5

        if not coordinates:
            res[0] = (row-1)*(col-1)
            return res

        matrix: List[List[int]] = [[0] * (col-1) for _ in range(row-1)]

        for c in coordinates:
            d = [[0, 0], [0, -1], [-1, 0], [-1, -1]]

            for idx in range(4):
                x_new, y_new = c[0]+d[idx][0], c[1]+d[idx][1]

                if x_new < 0 or y_new < 0:
                    continue

                if x_new >= row-1 or y_new >= col-1:
                    continue

                matrix[x_new][y_new] += 1

        for i in matrix:
            for j in i:
                res[j] += 1

        return res


s = Solution()

print(s.countBlackBlocks(3, 3, [[0, 0]]))
print(s.countBlackBlocks(3, 3, [[0, 0], [1, 1], [0, 2]]))

# Excessive mem usage
