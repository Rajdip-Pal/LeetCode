function concatenatedBinary(n: number): number {
    let res: bigint = 0n
    const MODULO: bigint = BigInt(1e9 + 7)

    for (let i = 1; i <= n; i++) {
        res = (BigInt(res << BigInt(Math.floor(Math.log2(i)) + 1)) | BigInt(i)) % MODULO
    }

    return Number(res)
};

console.log(
    concatenatedBinary(12)
)
console.log(Math.log2(1e5))

// console.log((Math.floor(Math.log2(7)) + 1))
