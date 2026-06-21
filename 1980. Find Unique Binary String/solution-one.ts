function findDifferentBinaryString(nums: string[]): string {

    const n: number = nums.length
    const num_set: Set<number> = new Set<number>()
    nums.forEach((n) => num_set.add(parseInt(n, 2) ?? -1))

    // no need of 2^n cause it says there will be n elements max in array so n+1 will make sure to find a absent number
    for (let i = 0; i <= n; i++) {
        if (!num_set.has(i)) return i.toString(2).padStart(n, '0')
    }

    // should never be reached
    return Number(-1).toString(2).padStart(n, '0')
};
