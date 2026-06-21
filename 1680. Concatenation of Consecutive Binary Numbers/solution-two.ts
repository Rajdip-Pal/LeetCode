function concatenatedBinary(n: number): number {
    let res: bigint = 0n
    let bit_len: bigint = 0n
    const MODULO: bigint = BigInt(1e9 + 7)

    for (let i = 1; i <= n; i++) {
        if ((i & (i - 1)) === 0) bit_len++
        res = ((res << bit_len) | BigInt(i)) % MODULO
    }

    return Number(res)
};

console.log(
    concatenatedBinary(12),
    concatenatedBinary(10005),
    concatenatedBinary(1e7),
    concatenatedBinary(10000)
)
