const cache: Map<number, number> = new Map<number, number>()

function fib(n: number): number {
    if (n === 0 || n === 1) return n

    if (!cache.has(n))
        cache.set(n, fib(n - 1) + fib(n - 2))

    return cache.get(n)!
};
