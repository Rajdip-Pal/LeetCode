type Pair = { first: number, second: number };

function f(n: number): Pair {
    if (n === 0) return { first: 0, second: 1 };

    const k = n >>> 1;
    const { first: fk, second: fk_next } = f(k);

    const f_2k = fk * (2 * fk_next - fk);
    const f_2k_next = fk * fk + fk_next * fk_next;

    if (n & 1)
        return { first: f_2k_next, second: (f_2k + f_2k_next) };
    else
        return { first: f_2k, second: f_2k_next };
};

function fib(n: number): number {
    return f(n).first;
}