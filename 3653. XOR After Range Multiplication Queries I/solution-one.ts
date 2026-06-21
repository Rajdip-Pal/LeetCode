function xorAfterQueries(nums: number[], queries: number[][]): number {
    const MOD = 1e9 + 7;

    for (const [l, r, k, v] of queries) {
        for (let idx = l; idx <= r; idx += k) {
            nums[idx] = (nums[idx] * v) % MOD;
        }
    }

    return nums.reduce((acc, val) => acc ^ val, 0);
}