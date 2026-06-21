function furthestDistanceFromOrigin(moves: string): number {

    // Note : every '_' should be replaced by 'L' or 'R' only
    // else if we assume opposite moves in empty places it will just go into waste.

    // Step 1 : Declaring variables curr and max distance.
    let curr: number = 0, maxDist: number = 0;

    const steps = moves.split('');

    // Step 2 : calculating for all empty as L
    steps.forEach(
        // just checking if it's not a 'R'
        (v) => { if (v != 'R') curr += 1; else curr -= 1 }
    )

    // set maximum
    maxDist = Math.max(maxDist, curr)

    // curr again to the 0 (reset to origin)
    curr = 0;

    // Step 3 : calculating for all empty as R
    steps.forEach(
        // just checking if it's not a 'L'
        (v) => { if (v != 'L') { curr += 1 } else curr -= 1 }
    )

    // set maximum
    maxDist = Math.max(maxDist, curr)

    return maxDist;
};