function cherryPickup(grid: number[][]): number {
    const rows: number = grid.length
    const cols: number = rows === 0 ? 0 : grid[0].length
    const dp: number[][][] = new Array(rows).fill(-1).map(() => new Array(cols).fill(-1).map(() => new Array(cols).fill(-1)))

    function solve(row: number, col1: number, col2: number): number {
        if (row >= rows) return 0;
        if (dp[row][col1][col2] !== -1)
            return dp[row][col1][col2]

        let cherry: number = grid[row][col1]
        if (col1 !== col2) cherry += grid[row][col2]

        let bottomMax: number = 0
        for (let val1 = -1; val1 <= 1; val1++) {
            for (let val2 = -1; val2 <= 1; val2++) {
                const nRow = row + 1
                const nCol1 = col1 + val1
                const nCol2 = col2 + val2

                if ((nCol1 >= 0 && nCol1 < cols) && (nCol2 >= 0 && nCol2 < cols))
                    bottomMax = Math.max(bottomMax, solve(nRow, nCol1, nCol2))
            }
        }

        return dp[row][col1][col2] = cherry + bottomMax
    }

    return solve(0, 0, cols - 1)
};
