function getSubarrayBeauty(nums: number[], k: number, x: number): number[] {
    const n: number = nums.length;
    const res: number[] = [];
    const freq: number[] = new Array(101).fill(0);

    function find_x_th_smallest(freq: number[]) {
        let count: number = 0;
        for (let i = -50; i <= 50; i++) {
            count += freq[i + 50];
            if (count >= x)
                return i;
        }
        return 50;
    }

    // doing till < k-1 cause in the next loop it will be easier to maintain.... the subarrays..
    for (let i = 0; i < k - 1; i++) freq[nums[i] + 50]++;
    for (let i = 0, j = k - 1; j < n; i++, j++) {
        freq[nums[j] + 50]++;

        const tmp = find_x_th_smallest(freq);
        res.push(tmp > 0 ? 0 : tmp);

        freq[nums[i] + 50]--;
    }

    return res;
};