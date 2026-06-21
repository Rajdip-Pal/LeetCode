function minPartitions(n: string): number {
    const set: Set<string> = new Set<string>(n.split(''));

    for (let ans = 9; ans > 0; ans--)
        if (set.has(`${ans}`)) return ans

    return 1
};
