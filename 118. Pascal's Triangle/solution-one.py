from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        triangle = [[1]]

        for _ in range(1, numRows):
            row = [1] + [triangle[-1][j-1] + triangle[-1][j]
                         for j in range(1, len(triangle[-1]))] + [1]
            triangle.append(row)

        return triangle
