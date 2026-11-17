function minMoves(nums: number[]): number {
    const max = Math.max(...nums);
    return nums.reduce((prev, curr) => prev + (max - curr), 0);
};