function countAnagrams(s: string): number {
    const mod = 1e9 + 7;
    const words = s.split(' ');
    const letters = new Array(26).fill(0);

    let result = 1;

    words.forEach((word, index) => {
        for (const char of word) {
            letters[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
    });
};
