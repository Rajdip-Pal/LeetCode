function minChanges(s: string): number {
    let currChar: number = s.charCodeAt(0);
    let length: number = 0;
    let res: number = 0;

    for (let i = 0; i < s.length; i++) {
        if (s.charCodeAt(i) === currChar) {
            length++;
        } else {
            if (length & 1) {
                res++;
                length = 0;
            } else {
                length = 1;
            }
            currChar = s.charCodeAt(i);
        }
    }

    return res;
};