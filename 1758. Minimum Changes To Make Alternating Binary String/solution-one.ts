function minOperations(s: string): number {
    if (s.length < 2) return 0

    const check = (even: string, odd: string) => {
        let count: number = 0;

        for (let i = 0; i < s.length; i++)
            (i & 1) ? (odd === s[i] ? null : count++) : (even === s[i] ? null : count++)

        return count
    }

    return Math.min(check('0', '1'), check('1', '0'))

};
