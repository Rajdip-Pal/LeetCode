function findDuplicates(nums: number[]): number[] {
    const freq: boolean[] = new Array(nums.length + 1).map(() => false);
    const res: Set<number> = new Set();

    nums.forEach((v) => freq[v] ? res.add(v) : (freq[v] = true));
    return [...res];
};