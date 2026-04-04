function decodeCiphertext(encodedText: string, rows: number): string {
    const row_len: number = Math.floor(encodedText.length / rows);
    let res: string[] = [];

    for (let i = 0; i < row_len; i++) {
        let idx: number = i
        for (let j = 0; (j < rows) && (idx < encodedText.length); j++) {
            res.push(encodedText[idx]);
            idx += row_len + 1;
        }
    }

    return res.join('').trimEnd();
};