function binary_search(nums: number[], left: number, right: number, target: number): { upper: number, lower: number } {
    if (left > right)
        return { upper: -1, lower: -1 }

    let mid: number = 0

    while (right >= left) {
        mid = Math.floor((left + right) / 2)
        if (nums[mid] === target)
            return { upper: mid, lower: mid }
        else if (nums[mid] > target)
            right = mid - 1
        else
            left = mid + 1
    }

    return { upper: left, lower: right }
}


function threeSumClosest(nums: number[], target: number): number {
    nums.sort((a, b) => a - b)

    const abs_compare = (a: number, b: number) => Math.abs(a - b)

    let res: number = Number(Infinity)

    for (let i = 0; i < nums.length - 2; i++) {
        for (let j = i + 1; j < nums.length - 1; j++) {
            const { upper, lower } = binary_search(nums, j + 1, nums.length - 1, target - nums[i] - nums[j])
            if (upper < nums.length && abs_compare(res, target) > abs_compare(nums[i] + nums[j] + nums[upper], target)) {
                res = nums[i] + nums[j] + nums[upper]
            }
            if (lower > j && abs_compare(res, target) > abs_compare(nums[i] + nums[j] + nums[lower], target)) {
                res = nums[i] + nums[j] + nums[lower]
            }
        }
    }

    return res
};


console.log(
    binary_search(
        [1, 5, 7, 9, 15, 17, 18, 20, 25], 0, 8, 27
    )
)
