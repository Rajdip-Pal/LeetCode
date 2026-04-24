function furthestDistanceFromOrigin(moves: string): number {
    let leftBias = 0;  // Treat '_' as 'L'
    let rightBias = 0; // Treat '_' as 'R'

    for (const move of moves) {
        // Case 1: Assume '_' behaves like 'L'
        if (move === 'R') leftBias--;
        else leftBias++;

        // Case 2: Assume '_' behaves like 'R'
        if (move === 'L') rightBias--;
        else rightBias++;
    }

    return Math.max(leftBias, rightBias);
}