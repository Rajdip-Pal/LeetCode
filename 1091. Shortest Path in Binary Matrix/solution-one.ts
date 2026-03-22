function shortestPathBinaryMatrix(grid: number[][]): number {
    const rows: number = grid.length;
    const cols: number = rows === 0 ? 0 : grid[0].length;

    const dfs = (i: number = 0, j: number = 0): number => {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] !== 0)
            return Infinity

        if (i == rows - 1 && j == cols - 1)
            return 1

        grid[i][j] = 1
        const t: number = Math.min(
            dfs(i - 1, j - 1), dfs(i - 1, j), dfs(i - 1, j + 1),
            dfs(i, j - 1), dfs(i, j + 1),
            dfs(i + 1, j - 1), dfs(i + 1, j), dfs(i + 1, j + 1)
        )
        grid[i][j] = 0

        return 1 + t
    }

    const res: number = dfs();
    return res === Infinity ? -1 : res;
};

// NO DFS -> TLE