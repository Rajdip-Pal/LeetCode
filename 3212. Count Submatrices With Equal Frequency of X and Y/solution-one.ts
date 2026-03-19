type Freq = { x: number, y: number }
enum Value { x = "X", y = "Y", null = "." }

function numberOfSubmatrices(grid: readonly string[][]): number {
    const rows: number = grid.length
    const cols: number = grid.length === 0 ? 0 : grid[0].length

    let result: number = 0
    let p_dp: Freq[], c_dp: Freq[] = Array(cols);

    const get_Freq = (ch: string): Freq => ({ x: ch === Value.x ? 1 : 0, y: ch === Value.y ? 1 : 0 })

    c_dp[0] = get_Freq(grid[0][0])

    for (let j = 1; j < cols; j++) {
        const t = get_Freq(grid[0][j]), p = c_dp[j - 1]
        c_dp[j] = { x: (p.x + t.x), y: (p.y + t.y) }
    }

    c_dp.forEach((v) => { if (v.x > 0 && v.x === v.y) result++ })

    p_dp = c_dp
    c_dp = Array(cols)

    for (let i = 1; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let a: Freq, b: Freq, c: Freq;

            a = p_dp[j], b = c = { x: 0, y: 0 }
            if (j > 0) b = c_dp[j - 1], c = p_dp[j - 1]

            const t = get_Freq(grid[i][j])
            c_dp[j] = { x: (a.x + b.x - c.x + t.x), y: (a.y + b.y - c.y + t.y) }
        }
        c_dp.forEach((v) => { if (v.x > 0 && v.x === v.y) result++ })

        p_dp = c_dp
        c_dp = Array(cols)
    }

    return result
};
