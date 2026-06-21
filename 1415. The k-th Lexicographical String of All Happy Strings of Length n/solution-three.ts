function getHappyString(n: number, k: number): string {

    if (k > 3 * (2 ** (n - 1))) return ''

    const res: string[] = []

    const backtrack = (i: number = 0, s: string[] = []) => {
        if (i === n) {
            res.push(s.join(''))
            if (res.length === k) return
        }
        else {
            if (s[s.length - 1] !== 'a') s.push('a'), backtrack(i + 1, s), s.pop()
            if (s[s.length - 1] !== 'b') s.push('b'), backtrack(i + 1, s), s.pop()
            if (s[s.length - 1] !== 'c') s.push('c'), backtrack(i + 1, s), s.pop()
        }
    }

    backtrack()
    return res[k - 1]
};
