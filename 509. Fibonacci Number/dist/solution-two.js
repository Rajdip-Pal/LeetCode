function f(n) {
    if (n === 0)
        return { first: 0, second: 1 };
    var k = n >>> 1;
    var _a = f(k), fk = _a.first, fk_next = _a.second;
    var f_2k = fk * (2 * fk_next - fk);
    var f_2k_next = fk * fk + fk_next * fk_next;
    if (n & 1)
        return { first: f_2k_next, second: (f_2k + f_2k_next) };
    else
        return { first: f_2k, second: f_2k_next };
}
;
function fib(n) {
    return f(n).first;
}
