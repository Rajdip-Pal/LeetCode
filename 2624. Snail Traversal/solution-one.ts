interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
}


Array.prototype.snail = function (rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount != this.length)
        return []
    else {
        const res: number[][] = new Array(rowsCount)
            .fill(0)
            .map(() => new Array(colsCount).fill(0));

        let idx: number = 0
        let i: number = 0, j: number = 0
        while (j < res[0].length) {
            if (i < 0 || i >= rowsCount) {
                ++j, (j & 1) ? i-- : i++;
                continue
            }
            res[i][j] = this.at(idx++);
            (j & 1) ? i-- : i++;
        }

        return res
    }
}

const arr = [19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15]
console.log(arr.snail(5, 4))
