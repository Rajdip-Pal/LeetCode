function firstMissingPositive(nums: number[]): number {
    nums.forEach((val) => {
        let target: number;

        while (true) {
            if (val < 1 || val > nums.length || nums[val - 1] === val)
                break
            target = nums[val - 1], nums[val - 1] = val
            val = target
        }
    })

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != i + 1) return i + 1
    }

    return nums.length + 1
};
