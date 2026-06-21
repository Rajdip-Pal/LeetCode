function valueAfterKSeconds(n, k) {
    var array = new Array(n).fill(1);
    var incr = function (times) {
        while (times--) {
            array.forEach(function (_, i, arr) {
                arr[i] += !!arr[i - 1] ? arr[i - 1] : 0;
            });
        }
    };
    incr(k);
    return array[array.length - 1];
}
;
valueAfterKSeconds(5, 1000);
