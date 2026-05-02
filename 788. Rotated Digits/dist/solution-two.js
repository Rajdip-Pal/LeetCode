var state;
(function (state) {
    state[state["invalid"] = 0] = "invalid";
    state[state["bad"] = 1] = "bad";
    state[state["good"] = 2] = "good";
})(state || (state = {}));
;
function rotatedDigits(n) {
    var dp = new Int32Array(n + 1).fill(state.invalid);
    dp[2] = dp[5] = dp[6] = dp[9] = state.good;
    dp[0] = dp[1] = dp[8] = state.bad;
    dp[3] = dp[4] = dp[7] = state.invalid;
    for (var i = 10; i <= n; i++) {
        var a = dp[Math.floor(i / 10)];
        var b = dp[i % 10];
        if (a === state.invalid || b === state.invalid)
            dp[i] = state.invalid;
        else if (a === state.bad && b === state.bad)
            dp[i] = state.bad;
        else
            dp[i] = state.good;
    }
    return dp.reduce(function (cnt, v) { return cnt + (v === state.good ? 1 : 0); }, 0);
}
;
