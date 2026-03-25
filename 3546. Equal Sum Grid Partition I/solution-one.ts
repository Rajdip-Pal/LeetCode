function canPartitionGrid(grid: number[][]): boolean {
    const m = grid.length, n = grid[0].length;

    const rowSum = new Array(m).fill(0);
    const colSum = new Array(n).fill(0);

    let total: number = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
            total += grid[i][j];
        }
    }

    if (total & 1) return false;

    const target: number = total / 2;

    // check horizontal cut
    let prefix: number = 0;
    for (let i = 0; i < m - 1; i++) {
        prefix += rowSum[i];
        if (prefix === target) return true;
    }

    // check vertical cut
    prefix = 0;
    for (let j = 0; j < n - 1; j++) {
        prefix += colSum[j];
        if (prefix === target) return true;
    }

    return false;
}