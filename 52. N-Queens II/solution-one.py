from typing import List


class Solution:
    def totalNQueens(self, n: int) -> int:
        board = [0]*n

        def backtrack(curr_row: int, n: int, res: int):
            res = 0

            def isValid(row, col):
                for i in range(row):
                    if board[i] == col or board[i] + i == col+row or board[i] - i == col-row:
                        return False
                return True

            if curr_row == n:
                return res + 1

            for j in range(n):
                if isValid(curr_row, j):
                    board[curr_row] = j
                    res += backtrack(curr_row+1, n, res)

            return res

        return backtrack(0, n, 0)
