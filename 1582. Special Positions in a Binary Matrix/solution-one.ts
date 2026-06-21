function numSpecial(mat: number[][]): number {
    return mat.reduce((count, row) => {
        const sum = row.reduce((a, b) => a + b, 0);
        if (sum === 1) {
            const j = row.findIndex(x => x === 1);
            if (mat.every(r => r[j] === 0 || r === row)) count++;
        }
        return count;
    }, 0);
};
