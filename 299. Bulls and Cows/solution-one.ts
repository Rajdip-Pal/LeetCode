function getHint(secret: string, guess: string): string {
    function get_digit_freq(str: string): number[] {
        const freq: number[] = new Array(10).fill(0);
        [...str].forEach((v) => freq[Number(v)]++);
        return freq;
    }

    const freq_secret: number[] = get_digit_freq(secret);
    const freq_guess: number[] = get_digit_freq(guess);

    const bulls = [...secret].reduce((prev, curr, index) => {
        if (curr === guess[index]) {
            freq_secret[Number(curr)]--;
            freq_guess[Number(curr)]--;
            return prev + 1;
        }
        return prev;
    }, 0);

    const cows = freq_secret.reduce((prev, curr, i) => prev + Math.min(curr, freq_guess[i]), 0)

    return `${bulls}A${cows}B`;
};