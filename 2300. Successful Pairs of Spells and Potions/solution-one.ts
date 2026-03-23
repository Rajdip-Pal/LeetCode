const upperBound = <T extends unknown>(arr: readonly T[], target: T, start: number, end: number) => {
    while (start < end) {
        const mid = start + ((end - start) >>> 1);

        if (arr[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }

    return start;
};

const lowerBound = <T extends unknown>(arr: readonly T[], target: T, start: number, end: number) => {
    while (start < end) {
        const mid = start + ((end - start) >>> 1);

        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    return start;
};

function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    const sortedPotions = [...potions].sort((a, b) => a - b);

    const res = spells.map(spell => {
        const target = Math.ceil(success / spell - 1);
        const idx = upperBound(sortedPotions, target, 0, sortedPotions.length);
        return sortedPotions.length - idx;
    });

    return res;
};