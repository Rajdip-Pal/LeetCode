const ascii = (ch: string) => ch.charCodeAt(0);

function wonderfulSubstrings(word: string): number {
    const state: number[] = new Array(26).map(() => 0);
    const prevOddMatrix: number[][] = new Array(word.length).map(() => new Array(26).map(() => 0));
    const prevEvenMatrix: number[][] = new Array(word.length).map(() => new Array(26).map(() => 0));

    for (let i = 0; i < word.length; i++) {
        const ch_index = ascii(word[i]) - ascii('a');
        const val = ++state[ch_index];

        if (val & 1) prevOddMatrix[i][ch_index] = 

        const prevOdd = prevOddMatrix[i];
        const prevEven = prevEvenMatrix[i];

        for (let k = 0; k < 26; k++) {

        }
    }

};