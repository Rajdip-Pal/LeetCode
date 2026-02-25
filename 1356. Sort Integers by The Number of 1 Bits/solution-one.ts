function sortByBits(arr: number[]): number[] {
    const countSetBits = function (n: number) {
        let count: number = 0
        while (n > 0) (n &= n - 1), count++
        return count
    }

    return arr.sort((a: number, b: number): number => {
        const res = countSetBits(a) - countSetBits(b)
        return res !== 0 ? res : a - b
    })
};
