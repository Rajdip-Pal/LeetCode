function firstPalindrome(words: string[]): string {

    const __is_palindrome = (word: string): boolean => {
        let l: number = 0, r: number = word.length - 1;
        while (l < r)
            if (word.charCodeAt(l++) !== word.charCodeAt(r--)) {
                return false;
            }
        return true;
    }

    return words.find(__is_palindrome) ?? "";
};