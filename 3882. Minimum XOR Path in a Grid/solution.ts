function minCost(grid: readonly number[][]): number {
    const m: number = grid.length;
    const n: number = m === 0 ? 0 : grid[0].length;

    const dp: Set<number>[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => new Set<number>()));

    dp[0][0].add(grid[0][0]);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) continue;

            if (i > 0)
                for (const x of dp[i - 1][j]) {
                    dp[i][j].add(x ^ grid[i][j]);
                }

            if (j > 0)
                for (const x of dp[i][j - 1]) {
                    dp[i][j].add(x ^ grid[i][j]);
                }
        }
    }

    // console.log(dp);

    return Math.min(...dp[m - 1][n - 1]);
};

console.log(minCost([[2, 4, 5], [1, 9, 8], [1, 6, 9]]));