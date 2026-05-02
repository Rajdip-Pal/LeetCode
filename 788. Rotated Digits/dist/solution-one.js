function build_validator(invalid_digits, rotating_digits) {
    return function (x) {
        var tmp = x;
        var invalid = false, rotating = false;
        while (!invalid && tmp > 0) {
            var digit = tmp % 10;
            if (invalid_digits.has(digit))
                invalid = true;
            if (rotating_digits.has(digit))
                rotating = true;
            tmp = Math.floor(tmp / 10);
        }
        return rotating && !invalid;
    };
}
function rotatedDigits(n) {
    var is_valid = build_validator(new Set([3, 4, 7]), new Set([2, 5, 6, 9]));
    var count = 0;
    for (var x = 1; x <= n; x++)
        if (is_valid(x))
            count++;
    return count;
}
;
