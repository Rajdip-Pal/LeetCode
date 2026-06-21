function map<T>(arr: T[], fn: (n: T, i: number) => T): T[] {
    const res: T[] = new Array(arr.length).fill(null)
    for (let idx = 0; idx < arr.length; idx++) res[idx] = fn(arr[idx], idx);
    return res;
};
