function minMoves(target: number, maxDoubles: number): number {
    if (target === 1) return 0

    let steps: number = 0

    while (target > 1) {
        if (!(target & 1) && (maxDoubles > 0)) maxDoubles--, steps++, target >>= 1
        else (maxDoubles > 0) ? (target--, steps++) : ((steps += target - 1), target = 1)
    }

    return steps
};
