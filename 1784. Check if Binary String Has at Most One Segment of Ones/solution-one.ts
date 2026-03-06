function checkOnesSegment(s: string): boolean {

    let i: number = 0

    while (i < s.length && s[i] === '0') i++
    while (i < s.length && s[i] === '1') i++

    while (i < s.length) {
        if (s[i] === '1') return false
        i++
    }

    return true
};
