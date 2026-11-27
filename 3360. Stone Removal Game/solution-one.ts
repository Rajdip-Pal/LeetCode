function canAliceWin(n: number, start: number = 10): boolean {
    let is_alice_win: boolean = false;
    let to_subtract: number = start;

    while (to_subtract > 0) {
        n -= to_subtract--;
        if (n < 0) break;
        is_alice_win = !is_alice_win;
    }

    return is_alice_win;
};