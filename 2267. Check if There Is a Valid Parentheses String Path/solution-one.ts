function hasValidPath(grid: readonly string[][]): boolean {
    const m = grid.length;
    const n = m === 0 ? 0 : grid[0].length;

    const dp: Array<Array<Array<boolean | null>>> =
        Array.from({ length: m },
            () => Array.from({ length: n },
                () => Array.from({ length: n + m + 1 },
                    () => null
                )
            )
        )

    const bactrack = (i: number = 0, j: number = 0, k: number = 0): boolean => {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (grid[i][j] === '(') k++; else k--;
        if (k < 0) return false;

        const remaining = (m - i - 1) + (n - j - 1);
        if (k > remaining) return false;

        if (dp[i][j][k] !== null)
            return dp[i][j][k]!;

        if (i === m - 1 && j === n - 1)
            return k === 0;

        return dp[i][j][k] = bactrack(i + 1, j, k) || bactrack(i, j + 1, k);
    }

    return bactrack(0, 0, 0);
};