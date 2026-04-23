function distance(nums: number[]): number[] {
    const mp: Map<number, Set<number>> = new Map();

    nums.forEach((num, i) => {
        if (!mp.has(num))
            mp.set(num, new Set());
        mp.get(num)?.add(i);
    })

    const res: Array<number> = Array.from({ length: nums.length }, () => 0);

    for (let i = 0; i < res.length; i++) {
        if (mp.get(nums[i])!.size >= 2) {
            for (const idx of mp.get(nums[i])!) {
                res[i] += Math.abs(idx - i);
            }
        }
    }

    return res;

};