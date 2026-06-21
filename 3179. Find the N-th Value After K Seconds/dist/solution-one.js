function valueAfterKSeconds(n, k) {
    var MODULO = 1e9 + 7;
    var array = new Array(n).fill(1);
    var incr = function (times) {
        while (times--) {
            array.forEach(function (_, i, arr) {
                arr[i] += !!arr[i - 1] ? arr[i - 1] : 0;
                arr[i] %= MODULO;
            });
        }
    };
    incr(k);
    return array[array.length - 1];
}
;
