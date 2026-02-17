const precomputed: string[][] = ((): string[][] => {
    const set_bits = new Array<number>(60).fill(0)

    function countSetBits(n: number, count: number = 0): number {
        return n == 0 ? count : countSetBits(n & (n - 1), count + 1)
    }

    set_bits.forEach((_, idx) => set_bits[idx] = countSetBits(idx))

    const map = Array.from<void, string[]>({ length: 11 }, (): string[] => new Array<string>(0))

    for (let h = 0; h < 12; h++)
        for (let m = 0; m < 60; m++)
            map[set_bits[h] + set_bits[m]].push(`${h}:${m.toString().padStart(2, "0")}`);

    return map
})()

function readBinaryWatch(turnedOn: number): string[] {
    return precomputed[turnedOn]
};

console.log(precomputed[0])
console.log(precomputed[1])
console.log(precomputed[0] === precomputed[1])

const func = (): string[] => new Array<string>(0)
