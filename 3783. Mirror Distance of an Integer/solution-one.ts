function mirrorDistance(n: number): number {
    return Math.abs(n - Number([...n.toString()].reverse().join('')))
};