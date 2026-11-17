function isodd(x: number): boolean {
    return Boolean(x & 1);
}

function numOfSubarrays(arr: number[]): number {
    const MOD: number = Number(1e9 + 7);

    let ans: number = 0;
    let curr_sum: number = 0, odd_sums: number = 0, even_sums: number = 0;
    let [prefix_sum, prev_odd_sums, prev_even_sums]: Array<Array<number>> = [[], [], []]

    for (let i = 0; i < arr.length; i++) {
        curr_sum += arr[i] + (i > 0 ? prefix_sum[i - 1] : 0);
        prefix_sum.push(curr_sum);
        prev_even_sums.push(even_sums);
        prev_odd_sums.push(odd_sums);
        isodd(curr_sum) ? odd_sums++ : even_sums++;
    }

    for (let i = 0; i < arr.length; i++) {
        if (isodd(prefix_sum[i])) {
            ans += 1 + prev_even_sums[i];
        } else {
            ans += prev_odd_sums[i];
        }
        ans %= MOD;
    }

    return ans;
};