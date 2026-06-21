function minFallingPathSum(matrix: number[][]): number {
    const rows: number = matrix.length
    const cols: number = rows === 0 ? 0 : matrix[0].length

    for (let i = 1; i < rows; i++)
        for (let j = 0; j < cols; j++) {
            let t: number = matrix[i - 1][j]

            if (j > 0)
                t = Math.min(t, matrix[i - 1][j - 1])
            if (j < cols - 1)
                t = Math.min(t, matrix[i - 1][j + 1])

            matrix[i][j] += t
        }

    return Math.min(...matrix[matrix.length - 1])
};

console.log(
    minFallingPathSum(
        [[2, 1, 3], [6, 5, 4], [7, 8, 9]]
    )
)
