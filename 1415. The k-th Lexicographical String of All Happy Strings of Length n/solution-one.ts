function getHappyString(n: number, k: number): string {

    const res: string[] = []

    const backtrack = (i: number = 0, s: string[] = []) => {
        if (i === n)
            res.push(s.join(''))
        else {
            if (s[s.length - 1] !== 'a') s.push('a'), backtrack(i + 1, s), s.pop()
            if (s[s.length - 1] !== 'b') s.push('b'), backtrack(i + 1, s), s.pop()
            if (s[s.length - 1] !== 'c') s.push('c'), backtrack(i + 1, s), s.pop()
        }
    }

    backtrack()
    return (k > res.length) ? '' : res[k - 1]
};
