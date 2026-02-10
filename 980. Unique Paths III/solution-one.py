from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start, goal, empty_blocks = (0, 0), (0, 0), 0

        res = 0
        rows, cols = len(grid), len(grid[0])

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    start = (r, c)
                elif grid[r][c] == 2:
                    goal = (r, c)
                if grid[r][c] != -1:
                    empty_blocks += 1

        print(start, goal, empty_blocks)

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        visited = set(tuple[int, int])

        visited.add(start)
        empty_blocks -= 1

        def dfs(curr: tuple[int, int]):
            nonlocal empty_blocks, visited, goal, res

            if curr == goal:
                if empty_blocks == 0:
                    res += 1
                return

            for i in range(4):
                r_new = curr[0] + dx[i]
                c_new = curr[1] + dy[i]

                if (0 <= r_new < rows) and ( 0 <= c_new < cols):

                    if grid[r_new][c_new] == -1:
                        continue

                    if (r_new,c_new) in visited :
                        continue

                    visited.add((r_new, c_new))
                    empty_blocks -= 1

                    print(r_new, c_new)
                    dfs((r_new, c_new))

                    visited.remove((r_new, c_new))
                    empty_blocks += 1

        dfs(start)

        return res
