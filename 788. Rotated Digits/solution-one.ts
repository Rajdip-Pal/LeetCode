function build_validator(invalid_digits: Set<number>, rotating_digits: Set<number>): (x: number) => boolean {

    return function (x: number): boolean {
        let tmp: number = x;
        let invalid: boolean = false, rotating: boolean = false;

        while (!invalid && tmp > 0) {
            const digit = tmp % 10;
            if (invalid_digits.has(digit)) invalid = true;
            if (rotating_digits.has(digit)) rotating = true;
            tmp = Math.floor(tmp / 10);
        }

        return rotating && !invalid;
    }
}

function rotatedDigits(n: number): number {
    const is_valid = build_validator(new Set([3, 4, 7]), new Set([2, 5, 6, 9]));
    let count: number = 0;
    for (let x = 1; x <= n; x++)
        if (is_valid(x)) count++;

    return count;
};