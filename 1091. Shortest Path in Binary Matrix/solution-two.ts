function shortestPathBinaryMatrix(grid: number[][]): number {
    const n = grid.length;
    if (grid[0][0] === 1 || grid[n - 1][n - 1] === 1) return -1;

    const qx: number[] = [0];
    const qy: number[] = [0];
    let head = 0;

    grid[0][0] = 1;
    let path = 1;

    while (head < qx.length) {
        const size = qx.length - head;

        for (let k = 0; k < size; k++) {
            const x = qx[head];
            const y = qy[head];
            head++;

            if (x === n - 1 && y === n - 1) return path;

            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    const nx = x + dx;
                    const ny = y + dy;

                    if (
                        nx >= 0 && ny >= 0 &&
                        nx < n && ny < n &&
                        grid[nx][ny] === 0
                    ) {
                        grid[nx][ny] = 1;
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
        }

        path++;
    }

    return -1;
}