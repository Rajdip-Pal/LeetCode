function countBinarySubstrings(s: string): number {
    let x: number = 1
    const arr: number[] = []
    let res: number = 0
    const collections: Set<string> = new Set([])

    for (let i = 1; i < s.length; i++) {
        if (s[i] !== s[i - 1]) arr.push(x), x = 0
        x++
    }
    arr.push(x)

    for (let i = 1; i < arr.length; i++) {
        res += Math.min(arr[i - 1], arr[i])
    }

    return res
};
