function minPathSum(grid: readonly number[][]): number {
    const rows: number = grid.length
    const cols: number = grid.length === 0 ? 0 : grid[0].length

    let curr_dp_array: number[] = Array.from({ length: cols }), prev_dp_array: number[] = []

    for (let i = 0; i < cols; i++) {
        curr_dp_array[i] = (curr_dp_array[i - 1] ?? 0) + grid[0][i]
    }

    prev_dp_array = curr_dp_array
    curr_dp_array = Array.from({ length: cols })

    for (let i = 1; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let a: number = 0, b: number = 0;
            a = prev_dp_array[j]
            b = curr_dp_array[j - 1] ?? Infinity
            curr_dp_array[j] = Math.min(a, b) + grid[i][j]
        }
        prev_dp_array = curr_dp_array
        curr_dp_array = Array.from({ length: cols })
    }

    return prev_dp_array[cols - 1]
};

console.log(
    minPathSum(
        [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    )
)
