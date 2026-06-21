function reverseSubmatrix(grid: number[][], x: number, y: number, k: number): number[][] {
    for (let r = x; r <= (x+ (k+x-1))/2; r++) {
        for (let c = y; c < (y+k); c++) {
            const i: number = r-x;
            const temp:number = grid[r][c];
            grid[r][c] = grid[k+x-1-i][c];
            grid[k+x-1-i][c] = temp;
        }
    }

    return grid
};