function containsCycle(grid: readonly string[][]): boolean {
    const m = grid.length, n = m === 0 ? 0 : grid[0].length;
    const visited: boolean[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => false));

    const dfs = (x: number, y: number, px: number, py: number) => {
        if (visited[x][y])
            return true;

        visited[x][y] = true;

        const ds = [0, 1, 0, -1, 0]
        for (let i = 0; i < 4; i++) {
            const nx = x + ds[i], ny = y + ds[i + 1];
            if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n))
                if (!(px === nx && py === ny) && grid[x][y] === grid[nx][ny] && dfs(nx, ny, x, y))
                    return true;
        }

        return false;
    }

    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (!visited[i][j] && dfs(i, j, -1, -1))
                return true;

    return false;
};
