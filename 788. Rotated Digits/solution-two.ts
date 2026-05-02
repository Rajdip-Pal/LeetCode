enum state { invalid, bad, good };

function rotatedDigits(n: number): number {
    const dp = new Int32Array(n + 1).fill(state.invalid);

    dp[2] = dp[5] = dp[6] = dp[9] = state.good;
    dp[0] = dp[1] = dp[8] = state.bad;
    dp[3] = dp[4] = dp[7] = state.invalid;

    for (let i = 10; i <= n; i++) {
        const a = dp[Math.floor(i / 10)];
        const b = dp[i % 10];

        if (a === state.invalid || b === state.invalid)
            dp[i] = state.invalid;
        else if (a === state.bad && b === state.bad)
            dp[i] = state.bad;
        else
            dp[i] = state.good;
    }

    return dp.reduce((cnt, v) => cnt + (v === state.good ? 1 : 0), 0);
};