function maxRotateFunction(nums) {
    var n = nums.length;
    if (n == 0)
        return 0;
    var total = nums.reduce(function (acc, v) { return acc + v; }, 0);
    var F = nums.reduce(function (acc, v, i) { return acc + i * v; }, 0);
    var max = F;
    for (var i = 1; i < n; i++)
        max = Math.max(max, F += total - n * nums[n - i]);
    return max;
}
;
