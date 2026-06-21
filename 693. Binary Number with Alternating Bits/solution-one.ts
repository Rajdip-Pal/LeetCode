function hasAlternatingBits(n: number): boolean {
    let a = n & 1
    n = n >> 1

    while (n > 0) {
        let b = n & 1;
        if (a == b) return false
        n = n >> 1
        a = b
    }

    return true
};
