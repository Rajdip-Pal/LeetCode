function minMoves2(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const mid = nums[Math.floor(nums.length / 2)];
    return nums.reduce((prev, curr) => prev + Math.abs(curr - mid), 0);
};