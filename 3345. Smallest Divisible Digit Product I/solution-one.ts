function product_of_digits(n: number) {
    let ans: number = 1;
    while (n > 0) {
        ans *= n % 10;
        n = Math.floor(n / 10);
    }
    return ans;
}

function smallestNumber(n: number, t: number): number {
    while (product_of_digits(n++) % t !== 0);
    return --n;
};
