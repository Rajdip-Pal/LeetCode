from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res: int = 0

        row_len: int = len(grid)
        col_len: int = len(grid[0])

        row: int = 0
        col: int = col_len - 1

        while row < row_len and col >= 0:
            if grid[row][col] < 0:
                res += row_len - row
                col -= 1
            else:
                row += 1

        return res


[
    [+4, +3, +2, -1],
    [+3, +2, +1, -1],
    [+1, +1, -1, -2],
    [-1, -1, -2, -3]
]
