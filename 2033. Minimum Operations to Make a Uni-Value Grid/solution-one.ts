function minOperations(grid: number[][], x: number): number {
    const array: number[] = [];
    grid.forEach((v1) => v1.forEach((v2) => array.push(v2)));

    const rem = array[0] % x;
    if (array.some((v) => v % x != rem))
        return -1;

    array.sort((a, b) => a - b);
    const mid = array[array.length >>> 1];

    const res = array.reduce((acc, v) => acc + Math.abs(v - mid) / x, 0);

    return res;
};