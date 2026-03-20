function minFallingPathSum(matrix: Readonly<number[][]>): number {
    const rows: number = matrix.length
    const cols: number = rows === 0 ? 0 : matrix[0].length

    const dp_size: number = rows * cols
    const dp: number[] = Array(dp_size).fill(Infinity)
    const dp_idx = (r: number, c: number) => r * cols + c

    const solve = (r: number, c: number): number => {
        if (c < 0 || c >= cols)
            return Infinity

        if (r == rows - 1)
            return matrix[r][c]

        if (dp[dp_idx(r, c)] !== Infinity)
            return dp[dp_idx(r, c)]

        let val: number = matrix[r][c]

        const t1: number = solve(r + 1, c - 1)
        const t2: number = solve(r + 1, c)
        const t3: number = solve(r + 1, c + 1)

        return dp[dp_idx(r, c)] = val + Math.min(t1, t2, t3)
    }

    let res: number = Infinity
    for (let i = 0; i < cols; i++) res = Math.min(res, solve(0, i))

    return res
};

console.log(
    minFallingPathSum(
        [[2, 1, 3], [6, 5, 4], [7, 8, 9]]
    )
)
