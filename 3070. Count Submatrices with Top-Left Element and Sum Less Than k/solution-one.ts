function countSubmatrices(grid: number[][], k: number): number {
    const rows: number = grid.length
    const cols: number = rows === 0 ? 0 : grid[0].length

    const dp: number[][] = grid

    let count: number = 0

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let a = 0, b = 0, c = 0;
            if (i - 1 >= 0) a = dp[i - 1][j]
            if (j - 1 >= 0) b = dp[i][j - 1]
            if ((i - 1 >= 0) && (j - 1 >= 0)) c = dp[i - 1][j - 1]
            dp[i][j] = a + b - c + dp[i][j]

            if (dp[i][j] <= k) count++
        }
    }

    return count
};
