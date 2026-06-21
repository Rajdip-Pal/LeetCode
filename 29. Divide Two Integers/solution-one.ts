const cache: number[] = new Array(50).fill(-1);
cache[0] = 1; cache[1] = 2

function expo(pow: number): number {
    if (cache[pow] !== -1) return cache[pow];
    else {
        const res = expo(pow >> 1) * expo(pow >> 1);
        return cache[pow] = (pow & 1) ? 2 * res : res;
    }
}

function divide(dividend: number, divisor: number): number {
    const isPos: boolean = (dividend < 0 === divisor < 0);

    let t_dividend = Math.abs(dividend);
    const t_divisor = Math.abs(divisor);

    let res: number = 0;

    while (t_dividend >= t_divisor) {
        let shifts: number = 0;
        while (((t_divisor << shifts) >>> 0) <= (t_dividend)) shifts++
        t_dividend -= ((t_divisor << (shifts - 1)) >>> 0);
        res += (1 << (shifts - 1)) >>> 0;
    }

    res = (isPos ? res : -res);
    if (res > ((1 << 31) >>> 0) - 1) return ((1 << 31) >>> 0) - 1;
    if (res < -((1 << 31) >>> 0)) return -((1 << 31) >>> 0);

    return res;
};