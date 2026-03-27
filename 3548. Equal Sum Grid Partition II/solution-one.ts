const bs = {
    find: function <T extends number>(arr: T[], val: T, coeff?: (arg: number) => T): number {
        let l = 0, r = arr.length - 1;

        while (l <= r) {
            const mid = (l + r) >>> 1;
            const mid_val = arr[mid] + (coeff ? coeff(mid) : 0);

            if (mid_val === val) return mid;
            else if (mid_val > val) r = mid - 1;
            else l = mid + 1;
        }

        return arr.length;
    },
};

function canPartitionGrid(grid: readonly number[][]): boolean {
    const m = grid.length;
    const n = m === 0 ? 0 : grid[0].length;

    const rowSum = new Array(m).fill(0);
    const colSum = new Array(n).fill(0);

    let total = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
            total += grid[i][j];
        }
    }

    for (let i = 1; i < m; i++) rowSum[i] += rowSum[i - 1];
    for (let j = 1; j < n; j++) colSum[j] += colSum[j - 1];

    const rem = total % 2;

    const is_conected = (rstart: number, rend: number, cstart: number, cend: number, i: number, j: number): boolean => {
        if (!((i >= rstart && i <= rend) && (j >= cstart && j <= cend))) return true;
        if ((rstart !== rend) && (cstart !== cend)) return true;
        if ((rstart === rend))
            if (i >= rstart && i <= rend)
                if ((j === cstart || j === cend)) return true;
                else return false
            else return true;
        if ((cstart === cend))
            if (j >= cstart && j <= cend)
                if ((i === rstart || i === rend)) return true;
                else return false;
            else return true;

        return false;
    }

    // ---- Case 1: no removal ----
    if (rem === 0) {
        if (bs.find(rowSum, total / 2) !== m) return true;
        if (bs.find(colSum, total / 2) !== n) return true;
    }

    // ---- Case 2: remove one cell ----
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {

            if (grid[i][j] % 2 !== rem) continue;

            const target = (total - grid[i][j]) / 2;

            const row_find = bs.find(rowSum, target, (idx) => idx >= i ? -grid[i][j] : 0);
            const col_find = bs.find(colSum, target, (idx) => idx >= j ? -grid[i][j] : 0);

            // horizontal cut
            if (row_find !== m) {
                if (is_conected(0, row_find, 0, n - 1, i, j) && is_conected(row_find + 1, m - 1, 0, n - 1, i, j)) {
                    return true;
                }
            }

            // vertical cut
            if (col_find !== n) {
                if (is_conected(0, m - 1, 0, col_find, i, j) && is_conected(0, m - 1, col_find + 1, n - 1, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}