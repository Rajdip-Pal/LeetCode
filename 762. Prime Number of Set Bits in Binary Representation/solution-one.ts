function countPrimeSetBits(left: number, right: number): number {
    const countSetBits = (n: number): number => {
        let bits: number = 0
        while (n > 0) { n &= n - 1, bits++ }
        return bits
    }

    const buildPrimeArray = (n: number): boolean[] => {
        const res: boolean[] = new Array(n).fill(true)

        res[0] = res[1] = false
        for (let i = 2; i < n; i++) {
            if (res[i] === true) {
                let coeff: number = 2
                while (i * coeff < n) {
                    res[i * (coeff++)] = false
                }
            }
        }

        return res
    }

    const primes = buildPrimeArray(64)

    let res: number = 0

    while (left <= right) if (primes[countSetBits(left++)]) res++

    return res
};

countPrimeSetBits(0, 0)
