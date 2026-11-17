function maxScore(s: string): number {
    const chars: string[] = [...s];
    let ones: number = chars.reduce((prev, v) => v === "1" ? prev + 1 : prev, 0), zeros = 0;

    let score: number = 0;
    chars.forEach(
        (v, i) => {
            if (v === '0') zeros++;
            if (v === '1') ones--;

            if (i === s.length - 1) { }
            else score = Math.max(score, zeros + ones);
        }
    )

    return score;
};