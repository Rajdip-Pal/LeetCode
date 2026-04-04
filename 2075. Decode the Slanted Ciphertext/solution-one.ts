function decodeCiphertext(encodedText: string, rows: number): string {
    const row_len: number = (encodedText.length / rows) >>> 0;
    let res: string[] = [];

    for (let i = 0; i < row_len; i++) {
        for (let j = 0; j < rows; j++) {
            const idx: number = i + j * row_len + j;
            if (idx < encodedText.length)
                res.push(encodedText[idx]);
        }
    }

    return res.join('').trimEnd();
};