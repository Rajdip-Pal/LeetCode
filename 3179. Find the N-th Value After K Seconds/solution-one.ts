function valueAfterKSeconds(n: number, k: number): number {
    const MODULO: number = 1e9 + 7;
    const array: number[] = new Array(n).fill(1);
    const incr = (times: number) => {
        while (times--) {
            array.forEach((_, i, arr) => {
                arr[i] += !!arr[i - 1] ? arr[i - 1] : 0;
                arr[i] %= MODULO;
            });
        }
    }
    incr(k);
    return array[array.length - 1];
};