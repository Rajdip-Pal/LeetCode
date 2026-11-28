const ascii = (ch: string) => ch.charCodeAt(0);

function minOperations(s: string): number {
    const chars: boolean[] = new Array(26);
    [...s].forEach((ch) => chars[ascii(ch) - ascii('a')] = true)

    const uniq: string[] =
        chars
            .map((v, i) => v ? i : -1)
            .filter((i) => !(i === 0 || i === -1))
            .map((i) => String.fromCharCode(i + ascii('a')));

    let total: number = 0;
    for (let i = 0; i < uniq.length; i++)
        total += (i === uniq.length - 1 ? 1 + ascii('z') : ascii(uniq[i + 1])) - ascii(uniq[i]);

    return total;
};