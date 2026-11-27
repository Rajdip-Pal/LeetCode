function ranges(arr: number[]) {
    let r: number[][] = [];

    for (let i = 0; i < arr.length; i++) {
        if (r.length <= 0 || arr[i] - r[r.length - 1][1] > 1) {
            r.push([arr[i], arr[i]]);
        } else {
            r[r.length - 1][1] = arr[i];
        }
    }

    return r;
}

function summaryRanges(nums: number[]): string[] {
    const r = ranges(nums);
    return r.map((v) => v[1] - v[0] ? `${v[0]}->${v[1]}` : `${v[0]}`);
};