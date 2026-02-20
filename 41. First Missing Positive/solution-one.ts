function firstMissingPositive(nums: number[]): number {
    const unique_num: Set<number> = new Set<number>()

    let positives: number = 0
    nums.forEach((val) => { if (val > 0) positives++, unique_num.add(val) })

    for (let i = 1; i <= positives; i++) {
        if (!unique_num.has(i))
            return i
    }

    return positives + 1
};
