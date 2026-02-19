function countBinarySubstrings(s: string): number {
    let curr: number = 1, last: number = 0;
    let res: number = 0

    for (let i = 1; i < s.length; i++, curr++)
        if (s[i] !== s[i - 1]) res += Math.min(last, curr), last = curr, curr = 0

    return res + Math.min(last, curr)
};
