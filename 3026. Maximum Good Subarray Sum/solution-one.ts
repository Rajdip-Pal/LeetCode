function maximumSubarraySum(nums: number[], k: number): number {
    const minPrefix = new Map<number, number>();

    let prefix = 0;
    let res = -Infinity;

    for (const num of nums) {
        // Check both possible starting values before updating prefix.
        const a = minPrefix.get(num - k);
        const b = minPrefix.get(num + k);

        if (a !== undefined) res = Math.max(res, prefix + num - a);
        if (b !== undefined) res = Math.max(res, prefix + num - b);

        // Prefix sum before this element is a possible starting prefix.
        const prevPrefix = prefix;
        prefix += num;

        const old = minPrefix.get(num);
        if (old === undefined || prevPrefix < old) {
            minPrefix.set(num, prevPrefix);
        }
    }

    return res === -Infinity ? 0 : res;
}