function maxRotateFunction(nums: readonly number[]): number {
    const n = nums.length;
    if (n == 0) return 0;

    const ans = new Int32Array(n);
    const total = nums.reduce((acc, v) => acc + v, 0);

    ans[0] = nums.reduce((acc, v, i) => acc + i * v, 0);
    ans[n - 1] = ans[0] + total - n * nums[n - 1];

    let max: number = Math.max(ans[0], ans[n - 1]);

    if (n > 2) {
        for (let i = n - 2; i > 0; i--)
            max = Math.max(max, ans[i] = ans[i + 1] + total - n * nums[i]);
    }

    return max;
};

// here i am storing thee factor by which rotation is happening 
// the answer is stored for that in ans[n-k] assume rotate by k factor
// but that's not the demand in question so going to eliminate that