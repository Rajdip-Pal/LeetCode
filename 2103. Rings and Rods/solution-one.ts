function countPoints(rings: string): number {
    const sets: Set<string>[] = Array.from({ length: 10 }, () => new Set())

    for (let i = 0; i < rings.length; i += 2)
        sets[parseInt(rings[i + 1])].add(rings[i])

    return sets.reduce((acc, v) => v.size === 3 ? acc + 1 : acc, 0)
};
