function reverseOnlyLetters(s: string): string {
    const chars: string[] = [...s];
    const n: number = chars.length;
    let first: number = 0, last: number = n - 1;

    function is_alphabet(ch: string) {
        const c = ch.charCodeAt(0);
        if ((c >= "a".charCodeAt(0) && c <= "z".charCodeAt(0)) || (c >= 'A'.charCodeAt(0) && c <= 'Z'.charCodeAt(0)))
            return true;
        return false;
    }

    while (first < last) {
        while (first < n && !is_alphabet(chars[first])) first++;
        while (last > -1 && !is_alphabet(chars[last])) last--;

        if (first < n && last > -1 && last > first)
            [chars[first], chars[last]] = [chars[last], chars[first]]

        first++, last--
    }

    return chars.join("");
};