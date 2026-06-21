function numSteps(s: string): number {
    if (s === "1") return 0;

    let steps: number = 0;
    let carry: number = 0;

    for (let i = s.length - 1; i > 0; i--)
        if (Number(s[i]) + carry === 1)
            carry = 1, steps += 2
        else
            steps += 1;

    return steps + carry;
}
