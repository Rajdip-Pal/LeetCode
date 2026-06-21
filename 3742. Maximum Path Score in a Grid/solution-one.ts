function maxPathScore(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0]?.length ?? 0;

    if (m === 0 || n === 0) {
        return -1;
    }

    const maxCost = Math.min(k, m + n - 2);
    const NEG_INF = -(1 << 30);
    const createState = (): Int32Array => new Int32Array(maxCost + 1).fill(NEG_INF);

    let previousRow: Int32Array[] = Array.from({ length: n }, createState);

    for (let row = 0; row < m; row++) {
        const currentRow: Int32Array[] = Array.from({ length: n }, createState);

        for (let col = 0; col < n; col++) {
            if (row === 0 && col === 0) {
                currentRow[col][0] = 0;
                continue;
            }

            const value = grid[row][col];
            const cost = value === 0 ? 0 : 1;

            for (let spent = cost; spent <= Math.min(k, row + col); spent++) {
                let best = NEG_INF;

                if (row > 0) {
                    best = Math.max(best, previousRow[col][spent - cost]);
                }

                if (col > 0) {
                    best = Math.max(best, currentRow[col - 1][spent - cost]);
                }

                if (best !== NEG_INF) {
                    currentRow[col][spent] = best + value;
                }
            }
        }

        previousRow = currentRow;
    }

    let answer = NEG_INF;
    for (let spent = 0; spent <= maxCost; spent++) {
        answer = Math.max(answer, previousRow[n - 1][spent]);
    }

    return answer < 0 ? -1 : answer;
}
