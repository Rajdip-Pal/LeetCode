function areSimilar(mat: number[][], k: number): boolean {
    const n = mat[0].length;
    k = k % n;

    if (!k) return true;

    for (let i = 0; i < mat.length; i++) {
        const shift = (i % 2 === 0 ? -k : k);
        if (!mat[i].every((v, idx, arr) => arr[(idx + shift + n) % n] === v)) {
            return false;
        }
    }

    return true;
};