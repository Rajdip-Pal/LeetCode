function constructProductMatrix(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const result: number[][] = Array.from({ length: m }, () => Array(n));

    const MODULO = 12345;

    let p: number = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            result[i][j] = p % MODULO;
            p = (p * grid[i][j]) % MODULO;
        }
    }

    let s: number = 1;
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            result[i][j] = (result[i][j] * s) % MODULO;
            s = (s * grid[i][j]) % MODULO;
        }
    }

    return result;
};