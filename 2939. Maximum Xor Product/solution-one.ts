function maximumXorProduct(a: number, b: number, n: number): number {
    const MOD = 1000000007n;

    let A = BigInt(a);
    let B = BigInt(b);

    // keep higher bits fixed
    const mask = (1n << BigInt(n)) - 1n;
    let highA = A & ~mask;
    let highB = B & ~mask;

    let xA = highA;
    let xB = highB;

    for (let i = n - 1; i >= 0; i--) {
        const bit = 1n << BigInt(i);

        const ai = (A & bit) !== 0n;
        const bi = (B & bit) !== 0n;

        if (ai === bi) {
            // make both bits 1
            xA |= bit;
            xB |= bit;
        } else {
            // give bit to smaller number
            if (xA < xB) xA |= bit;
            else xB |= bit;
        }
    }

    return Number((xA % MOD) * (xB % MOD) % MOD);
}
