function findTargetSumWays(nums: number[], target: number): number {

    let ways: number = 0;

    function dfs(index: number = 0, sum: number = 0) {
        if (index >= nums.length) {
            if (target === sum) ways++;
            return
        }

        dfs(index + 1, sum + nums[index])
        dfs(index + 1, sum - nums[index])
    }

    dfs(0)

    return ways
};


console.log(findTargetSumWays([1, 1, 1, 1, 1], 3))
