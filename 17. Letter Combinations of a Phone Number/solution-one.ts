function letterCombinations(digits: string): string[] {
    if (digits.length === 0) return []

    const res: string[] = []
    const numToLetters: Record<string, string> = {
        1: '', 2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl', 6: 'mno', 7: 'pqrs', 8: 'tuv', 9: 'wxyz'
    }

    const subseq = (digits: string, idx: number, word: string) => {
        if (idx >= digits.length)
            res.push(word)
        else {
            for (const letter of numToLetters[digits[idx]]) {
                subseq(digits, idx + 1, word + letter)
            }
        }
    }

    subseq(digits, 0, "")

    return res
};
