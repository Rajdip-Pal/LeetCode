function makeLargestSpecial(s: string): string {
    if (s === '')
        return ''

    let count: number = 0
    const res: string[] = []
    let start: number = 0


    for (let i = 0; i < s.length; i++) {
        (s[i] === '1') ? count++ : count--

        if (count === 0)
            res.push('1' + makeLargestSpecial(s.slice(start + 1, i)) + '0'),
                start = i + 1
    }

    return res.sort().reverse().join('')
};

/**
 * Inspired Solution from : -> https://leetcode.com/problems/special-binary-string/solutions/7593016/recursive-divide-conquer-sort-balanced-c-drb6
 */
