function gcd(arr: number[]) {
    const __gcd = (a: number, b: number): number => {
        if (!b) return a;
        return a < b ? __gcd(b, a) : __gcd(b, a % b)
    }

    return arr.reduce((prev, curr) => __gcd(prev, curr), 0);
}

function lcm(arr: number[]) {
    const __lcm = (a: number, b: number) => {
        if (a === 0 || b === 0) return 0;
        return (a / gcd([a, b])) * b;
    }

    return arr.reduce((prev, curr) => __lcm(prev, curr), 1);
}


function product(arr: number[]) {
    return arr.reduce((prev, curr) => prev * curr, 1);
}


function maxLength(nums: number[]): number {
    let maxLength: number = 1;

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            const arr = nums.slice(i, j + 1);
            if (product(arr) === gcd(arr) * lcm(arr)) {
                maxLength = Math.max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
};