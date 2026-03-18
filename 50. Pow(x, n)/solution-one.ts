function myPow(x: number, n: number): number {
    return n > 0 ? binary_expo(x, n) : binary_expo(1 / x, -n)
};

function binary_expo(x: number, n: number): number {
    let result: number = 1

    while (n > 0) {
        if (n & 1) result *= x
        x *= x
        n >>>= 1
    }

    return result
}


console.log(
    myPow(
        2, -2147483648
    )
)
