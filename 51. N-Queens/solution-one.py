from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [0]*n
        res = []

        def backtrack(curr_row: int, n: int, res: List[List[str]]):

            def isValid(row, col):
                for i in range(row):
                    if board[i] == col or board[i] + i == col+row or board[i] - i == col-row:
                        return False
                return True

            def generate(board: List[int]):
                return ["."*i + "Q" + "."*(len(board)-i-1) for i in board]

            if curr_row == n:
                res.append(generate(board))
                return

            for j in range(n):
                if isValid(curr_row, j):
                    board[curr_row] = j
                    backtrack(curr_row+1, n, res)

        backtrack(0, n, res)

        return res


'''
    [][][][][]
    [][][][][]
    [][][][][]
    [][][][][]

    [....]


'''
