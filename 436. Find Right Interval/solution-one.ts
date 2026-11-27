const lower_bound = <T, K>(arr: T[], target: K, compare: (a: T, b: K) => number): number => {
    let l = 0, r = arr.length;

    while (l < r) {
        const mid = l + ((r - l) >>> 1);
        const cmp = compare(arr[mid], target);

        if (cmp < 0) l = mid + 1;
        else r = mid;
    }

    return l;
}

function findRightInterval(intervals: number[][]): number[] {
    const orders = new Map<number, number>();
    const clone = [...intervals].sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    intervals.forEach((v, i) => orders.set(v[0], i));

    return intervals.map((v, i) => {
        if (v[0] >= v[1]) return i;
        const index = lower_bound(clone, v[1], (a, b) => a[0] - b);
        return index === intervals.length ? -1 : orders.get(clone[index][0])!;
    });
};