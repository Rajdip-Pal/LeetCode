function numPairsDivisibleBy60(time: number[], factor: number = 60): number {
    const half_factor = Math.floor(factor / 2);
    time.forEach((t, i) => time[i] = t % factor);

    let pairs: number = 0;
    let zeros: number = 0, halfs: number = 0;
    const left = Array.from({ length: half_factor + 1 }, () => 0);
    const right = Array.from({ length: half_factor + 1 }, () => 0);

    for (let i = 0; i < time.length; i++) {
        if (time[i] === 0) zeros++;
        else if (time[i] === half_factor) halfs++;
        else if (time[i] < half_factor) left[time[i]]++;
        else right[factor - time[i]]++;
    }

    for (let i = 0; i < half_factor + 1; i++) {
        pairs += left[i] * right[i];
    }

    console.log(time, zeros, left, right)

    return pairs + (((zeros - 1) * zeros) / 2) + (((halfs - 1) * halfs) / 2);
};