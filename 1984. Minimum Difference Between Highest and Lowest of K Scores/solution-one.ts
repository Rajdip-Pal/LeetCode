function minimumDifference(nums: number[], k: number): number {
    const sorted_nums: number[] = Array.from(nums).sort((a, b) => b - a)

    let first: number = 0, last: number = k - 1;
    let res: number = Infinity

    while (last < nums.length)
        res = Math.min(res, sorted_nums[first++] - sorted_nums[last++])

    return res
};
