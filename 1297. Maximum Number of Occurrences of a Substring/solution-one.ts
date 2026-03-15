function maxFreq(s: string, maxLetters: number, minSize: number, maxSize: number): number {

    let freq: number = 0;

    for (let size = minSize; size <= maxSize; size++) {
        if (size > s.length) break

        let first: number = 0, last: number = size - 1;
        const mp: Map<string, number> = new Map();

        const char_mp: number[] = Array.from({ length: 26 }, () => 0)
        for (let i = first; i <= last; i++) char_mp[s.charCodeAt(i) - 'a'.charCodeAt(0)]++

        while (last < s.length) {
            // console.log(char_mp.reduce((pre, v) => v === 0 ? pre : pre + 1, 0))
            if (char_mp.reduce((pre, v) => v === 0 ? pre : pre + 1, 0) <= maxLetters) {
                const substr: string = s.slice(first, last + 1)
                const occr: number = mp.get(substr) ?? 0
                mp.set(substr, occr + 1)

                if (occr + 1 > freq) freq = occr + 1
            }
            char_mp[s.charCodeAt(first) - 'a'.charCodeAt(0)]--
            last += 1, first += 1
            if (last < s.length) char_mp[s.charCodeAt(last) - 'a'.charCodeAt(0)]++
        }
    }

    return freq
};
