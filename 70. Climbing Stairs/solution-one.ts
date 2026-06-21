const memory: Map<number, number> = new Map<number, number>()

function climbStairs(n: number): number {
    if (n == 1) return 1
    if (n == 2) return 2

    if (!memory.has(n))
        memory.set(n, climbStairs(n - 1) + climbStairs(n - 2))

    return memory.get(n)!
};
