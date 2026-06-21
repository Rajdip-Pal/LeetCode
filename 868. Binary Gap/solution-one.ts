function binaryGap(n: number): number {
    const binary: string = n.toString(2)
    let maxGap: number = 0

    let i: number = 0
    while (binary[i] !== '1') i++

    for (let j = i + 1; j < binary.length; j++) {
        if (binary[j] === '1')
            maxGap = Math.max(maxGap, j - i), i = j
    }

    return maxGap
};
