const cache: Map<number, number> = new Map<number, number>()

function tribonacci(n: number): number {
    if (n === 0 || n === 1) return n
    if (n == 2) return 1

    if (!cache.has(n))
        cache.set(n, tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3))

    return cache.get(n)!
};
