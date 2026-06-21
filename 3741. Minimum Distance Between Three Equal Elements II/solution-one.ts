function minimumDistance(nums: number[]): number {
    const mp: Map<number, Array<number>> = new Map();
    nums.forEach((v, i) => {
        if (!mp.has(v)) mp.set(v, new Array());
        mp.get(v)?.push(i)
    })

    let res: number = 1e18;

    for (const [k, v] of mp) {
        if (v.length >= 3) {
            for (let i = 0; i < v.length - 2; i++) {
                res = Math.min(res, 2 * (v[i + 2] - v[i]));
            }
        }
    }

    return res !== 1e18 ? res : -1;
};