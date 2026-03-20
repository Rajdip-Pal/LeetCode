function cherryPickup(grid: Readonly<number[][]>): number {

    const rows: number = grid.length
    const cols: number = grid[0].length
    const size = rows * cols * rows * cols;
    const dp = new Array(size).fill(-1);

    function get_idx(i: number, j: number, k: number, l: number): number {
        return ((i * cols + j) * rows + k) * cols + l;
    }

    const solve = (row1: number, col1: number, row2: number, col2: number): number => {
        if (row1 >= rows || row2 >= rows || col1 >= cols || col2 >= cols || grid[row1][col1] === -1 || grid[row2][col2] === -1)
            return -Infinity

        if (dp[get_idx(row1, col1, row2, col2)] != -1)
            return dp[get_idx(row1, col1, row2, col2)]

        if (row1 == rows - 1 && col1 == cols - 1)
            return grid[row1][col1]

        let cherries: number = grid[row1][col1]
        if (row1 !== row2 || col1 !== col2) cherries += grid[row2][col2]

        const t1: number = solve(row1 + 1, col1, row2 + 1, col2)
        const t2: number = solve(row1 + 1, col1, row2, col2 + 1)
        const t3: number = solve(row1, col1 + 1, row2 + 1, col2)
        const t4: number = solve(row1, col1 + 1, row2, col2 + 1)

        return dp[get_idx(row1, col1, row2, col2)] = cherries + Math.max(t1, t2, t3, t4)
    }

    const res: number = solve(0, 0, 0, 0)
    return res > 0 ? res : 0
};
