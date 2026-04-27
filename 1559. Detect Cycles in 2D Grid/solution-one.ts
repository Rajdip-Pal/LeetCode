function containsCycle(grid: readonly string[][]): boolean {
    const m = grid.length, n = m === 0 ? 0 : grid[0].length;
    const visiting: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => -1));

    const dfs = (x: number, y: number, idx: number, minPathLength: number) => {
        if (visiting[x][y] !== -1)
            return (idx - visiting[x][y]) >= minPathLength;

        visiting[x][y] = idx;

        const ds = [0, 1, 0, -1, 0]
        for (let i = 0; i < 4; i++) {
            const nx = x + ds[i], ny = y + ds[i + 1];
            if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n))
                if (grid[x][y] === grid[nx][ny] && dfs(nx, ny, idx + 1, minPathLength))
                    return true;
        }

        return false;
    }

    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (visiting[i][j] === -1 && dfs(i, j, 1, 4))
                return true;

    return false;
};