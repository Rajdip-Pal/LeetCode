function findTargetSumWays(nums: number[], target: number): number {

    let dp: Map<number, number> = new Map()
    dp.set(0, 1)

    for (let i = 0; i < nums.length; i++) {
        let nextDp: typeof dp = new Map()

        dp.forEach((v, k) => {
            nextDp.set(k + nums[i], nextDp.has(k + nums[i]) ? nextDp.get(k + nums[i])! + v : v)
            nextDp.set(k - nums[i], nextDp.has(k - nums[i]) ? nextDp.get(k - nums[i])! + v : v)
        })

        dp = nextDp
    }

    return dp.get(target) ?? 0
};


console.log(findTargetSumWays([1, 1, 1, 1, 1], 3))
