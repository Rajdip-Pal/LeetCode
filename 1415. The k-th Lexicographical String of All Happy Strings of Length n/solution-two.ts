function getHappyString(n: number, k: number): string {
    const total_strings: number = 3 * (2 ** (n - 1))
    const res: string[] = []

    if (k > total_strings) return ''

    let temp: number = total_strings / 3;
    let first: number = 0, last: number = total_strings;

    if (k < temp) res.push('a'), first = 0, last = temp
    else if (k < 2 * temp) res.push('b'), first = temp + 1, last = 2 * temp
    else res.push('c'), first = 2 * temp + 1, last = total_strings

    n -= 1;

    let mid: number = (first + last) / 2;
    while (n > 0 && last >= first) {
        mid = Math.floor((first + last) / 2);

        if (mid === k) {
            res.push(res[res.length - 1] === 'a' ? 'b' : 'a')
            first = mid - 1, last = mid + 1
        }
        else if (mid > k)
            res.push(res[res.length - 1] === 'a' ? 'b' : 'a'), last = mid - 1
        else
            res.push(res[res.length - 1] === 'c' ? 'b' : 'c'), first = mid + 1

        n--
    }

    return res.join('')
};

// Maybe not a soultion
