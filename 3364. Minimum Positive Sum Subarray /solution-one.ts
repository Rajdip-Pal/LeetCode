function minimumSumSubarray(nums: number[], l: number, r: number): number {
    let ans: number = Infinity;

    for (let window = l; window <= r; window++) {
        let curr: number = 0;
        let i = 0;

        for (; i < l; i++) {
            curr += nums[i];
        }

        while (i < nums.length) {

        }
    }

    return ans === Infinity ? -1 : ans;
};