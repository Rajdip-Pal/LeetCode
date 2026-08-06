function product_of_digits(n) {
    var ans = 1;
    while (n > 0) {
        ans *= n % 10;
        n = Math.floor(n / 10);
    }
    return ans;
}
function smallestNumber(n, t) {
    while (product_of_digits(n++) % t !== 0)
        ;
    return --n;
}
;
