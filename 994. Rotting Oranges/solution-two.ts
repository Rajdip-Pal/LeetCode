function orangesRotting(grid: number[][]): number {
    const m: number = grid.length;
    const n: number = m === 0 ? 0 : grid[0].length;

    const ds: number[] = [0, 1, 0, -1, 0];

    const qx: number[] = []
    const qy: number[] = []
    let head: number = 0;

    let fresh_count: number = 0;

    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (grid[i][j] === 2) qx.push(i), qy.push(j)
            else if (grid[i][j] === 1) fresh_count++;

    if (fresh_count == 0)
        return 0;

    if (qx.length === 0)
        return -1;

    let minutes: number = 0;
    while (head < qx.length && fresh_count > 0) {
        const size: number = qx.length - head;
        for (let i = 0; i < size; i++) {
            const x: number = qx[head];
            const y: number = qy[head];
            head++;

            for (let d = 0; d < 4; d++) {
                const nx = x + ds[d];
                const ny = y + ds[d + 1];

                if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n)) {
                    if (grid[nx][ny] === 1) {
                        grid[nx][ny] = 2;
                        fresh_count--;
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
        }

        minutes++;
    }

    return fresh_count > 0 ? -1 : minutes;
};