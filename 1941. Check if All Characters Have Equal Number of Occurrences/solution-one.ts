function areOccurrencesEqual(s: string): boolean {
    const frequency: number[] = Array.from({ length: 26 }, () => 0);
    for (let i = 0; i < s.length; i++) frequency[s.charCodeAt(i) - 'a'.charCodeAt(0)]++
    return !frequency.some((v, _, a) => v !== 0 && v !== a[s.charCodeAt(0) - 'a'.charCodeAt(0)])
};

console.log(areOccurrencesEqual('abc'))
console.log(areOccurrencesEqual('abcabc'))
console.log(areOccurrencesEqual('abca'))
console.log(areOccurrencesEqual('abcbca'))
