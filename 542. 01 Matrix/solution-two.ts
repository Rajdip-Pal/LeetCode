function updateMatrix(mat: number[][]): number[][] {
    const rows: number = mat.length;
    const cols: number = rows === 0 ? 0 : mat[0].length;

    const ds: number[] = [0, 1, 0, -1, 0];

    const qx: number[] = [];
    const qy: number[] = [];
    let head: number = 0;

    for (let i = 0; i < rows; i++)
        for (let j = 0; j < cols; j++)
            if (mat[i][j]) mat[i][j] = -1;
            else qx.push(i), qy.push(j);

    while (head < qx.length) {
        const size: number = qx.length - head;

        for (let i = 0; i < size; i++) {
            const x: number = qx[head];
            const y: number = qy[head];
            head++;

            for (let d = 0; d < 4; d++) {
                const nx = x + ds[d];
                const ny = y + ds[d + 1];

                if ((nx >= 0 && nx < rows) && (ny >= 0 && ny < cols)) {
                    if (mat[nx][ny] === -1) {
                        mat[nx][ny] = mat[x][y] + 1;
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
        }
    }

    return mat;
};