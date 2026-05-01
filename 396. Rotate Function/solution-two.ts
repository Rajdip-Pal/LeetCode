function maxRotateFunction(nums: Int32Array): number {
    const n = nums.length;
    if (n == 0) return 0;

    const total = nums.reduce((acc, v) => acc + v, 0);

    let F: number = nums.reduce((acc, v, i) => acc + i * v, 0);
    let max: number = F;

    for (let i = 1; i < n; i++)
        max = Math.max(max, F += total - n * nums[n - i]);

    return max;
};