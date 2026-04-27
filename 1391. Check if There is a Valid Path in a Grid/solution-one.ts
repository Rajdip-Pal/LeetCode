function hasValidPath(grid: readonly number[][]): boolean {
    const m = grid.length;
    const n = m === 0 ? 0 : grid[0].length;

    // 0: up, 1: right, 2: down, 3: left
    const dirs = [
        [-1, 0],
        [0, 1],
        [1, 0],
        [0, -1]
    ];

    // 0: up, 1: right, 2: down, 3: left
    const streetMap: Record<number, number[]> = {
        1: [1, 3],
        2: [0, 2],
        3: [2, 3],
        4: [1, 2],
        5: [0, 3],
        6: [0, 1],
    };

    const isValid = (cx: number, cy: number, nx: number, ny: number): boolean => {
        const currType = grid[cx][cy];
        const nextType = grid[nx][ny];

        const dx = nx - cx, dy = ny - cy;

        let dir: number = -1;
        for (let i = 0; i < 4; i++) {
            if (dirs[i][0] === dx && dirs[i][1] === dy) {
                dir = i; break;
            }
        }

        if (dir === -1) return false;

        const opposite = (dir + 2) % 4;
        return streetMap[currType].includes(dir) && streetMap[nextType].includes(opposite);
    }

    const visited = Array.from({ length: m }, () => Array.from({ length: n }, () => false));

    const dfs = (x: number = 0, y: number = 0) => {
        if (x === m - 1 && y === n - 1)
            return true;

        visited[x][y] = true;
        for (const d of dirs) {
            const nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!visited[nx][ny] && isValid(x, y, nx, ny) && dfs(nx, ny))
                return true;
        }

        return false;
    };

    return dfs();
};