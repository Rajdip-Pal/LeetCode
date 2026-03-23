function maxProductPath(grid: number[][]): number {
    const MOD: number = Number(1e9 + 7);
    const m: number = grid.length;
    const n: number = m === 0 ? 0 : grid[0].length;

    const dp_size: number = m * n * 2;
    const dp: number[] = new Array(dp_size);

    const dp_idx = (i: number, j: number, k: number) => {
        return (i * n + j) * 2 + k;
    }

    dp[dp_idx(0, 0, 0)] = grid[0][0]
    dp[dp_idx(0, 0, 1)] = grid[0][0]

    for (let i = 1; i < m; i++) {
        dp[dp_idx(i, 0, 0)] = dp[dp_idx(i - 1, 0, 0)] * grid[i][0];
        dp[dp_idx(i, 0, 1)] = dp[dp_idx(i - 1, 0, 1)] * grid[i][0];
    }

    for (let i = 1; i < n; i++) {
        dp[dp_idx(0, i, 0)] = dp[dp_idx(0, i - 1, 0)] * grid[0][i];
        dp[dp_idx(0, i, 1)] = dp[dp_idx(0, i - 1, 1)] * grid[0][i];
    }

    for (let i = 1; i < m; i++)
        for (let j = 1; j < n; j++)
            if (grid[i][j] > 0) {
                dp[dp_idx(i, j, 0)] = Math.max(dp[dp_idx(i - 1, j, 0)], dp[dp_idx(i, j - 1, 0)]) * grid[i][j]
                dp[dp_idx(i, j, 1)] = Math.min(dp[dp_idx(i - 1, j, 1)], dp[dp_idx(i, j - 1, 1)]) * grid[i][j]
            }
            else {
                dp[dp_idx(i, j, 1)] = Math.max(dp[dp_idx(i - 1, j, 0)], dp[dp_idx(i, j - 1, 0)]) * grid[i][j]
                dp[dp_idx(i, j, 0)] = Math.min(dp[dp_idx(i - 1, j, 1)], dp[dp_idx(i, j - 1, 1)]) * grid[i][j]
            }

    return dp[dp_idx(m - 1, n - 1, 0)] >= 0 ? dp[dp_idx(m - 1, n - 1, 0)] % MOD : -1
};