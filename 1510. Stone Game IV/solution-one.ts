function square_root(n: number) {
    if (n < 2) return n;

    let l: number = 1, r: number = n;
    let ans: number = 0;

    while (l <= r) {
        const m = l + ((r - l) >>> 1);

        if (m <= n / m) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }

    return ans;
}

function winnerSquareGame(n: number): boolean {
    let is_alice_win: boolean = false;

    let sq = square_root(n);
    let to_subtract: number = sq * sq;

    while (to_subtract > 0) {
        n -= to_subtract;
        if (n <= 0) break;
        sq = square_root(n);
        to_subtract = sq * sq;
        is_alice_win = !is_alice_win;
    }

    return is_alice_win;
};