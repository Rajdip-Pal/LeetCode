function hasAllCodes(s: string, k: number): boolean {
    const seen = new Set<string>();
    for (let i = 0; i <= s.length - k; i++) {
        const substring = s.substring(i, i + k);
        seen.add(substring);
    }
    return seen.size === 1 << k;
};
