const rotateMatrix = (mat: number[][]) => {
    const m = mat.length;
    const n = m == 0 ? 0 : mat[0].length;

    const res: Array<Array<number>> = Array.from({ length: n }, () => new Array(m))

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            res[n - j - 1][i] = mat[i][j]
        }
    }

    return res;
}

const matchMatrix = (mat1: readonly number[][], mat2: readonly number[][]) => {
    const r1 = mat1.length;
    const c1 = r1 === 0 ? 0 : mat1[0].length;

    const r2 = mat2.length;
    const c2 = r2 === 0 ? 0 : mat2[0].length;

    if (r1 === r2 && c1 === c2) {
        for (let i = 0; i < r1; i++)
            for (let j = 0; j < c1; j++)
                if (mat1[i][j] !== mat2[i][j])
                    return false

        return true
    }

    return false
}

function findRotation(mat: number[][], target: number[][]): boolean {
    let temp = mat;
    for (let i = 0; i < 4; i++) {
        console.log(temp);
        if (matchMatrix(temp, target))
            return true;
        temp = rotateMatrix(temp);
    }
    return false;
};