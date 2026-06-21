const obj = { empty: 0, obstacle: 1 } as const;

function minimumObstacles(grid: readonly number[][]): number {
    const m = grid.length;
    const n = grid[0]?.length ?? 0;
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]] as const;

    const dist: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    const deque: [number, number][] = Array.from({ length: (m * n * 2) + 1 }, () => [0, 0]);
    let head = m * n;
    let tail = m * n;

    dist[0][0] = 0;
    deque[tail] = [0, 0];

    while (head <= tail) {
        const [x, y] = deque[head++];

        for (const [dx, dy] of directions) {
            const nextX = x + dx;
            const nextY = y + dy;

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;

            const weight = grid[nextX][nextY] === obj.obstacle ? 1 : 0;
            const nextDist = dist[x][y] + weight;

            if (nextDist >= dist[nextX][nextY])
                continue;

            dist[nextX][nextY] = nextDist;

            if (weight === obj.empty) {
                deque[--head] = [nextX, nextY];
            } else {
                deque[++tail] = [nextX, nextY];
            }
        }
    }

    return dist[m - 1][n - 1];
}

console.log(
    minimumObstacles([[0, 1, 1], [1, 1, 0], [1, 1, 0]])
)