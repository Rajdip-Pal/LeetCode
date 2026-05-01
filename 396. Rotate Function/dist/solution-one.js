function maxRotateFunction(nums) {
    var n = nums.length;
    if (n == 0)
        return 0;
    var ans = new Int32Array(n);
    var total = nums.reduce(function (acc, v) { return acc + v; }, 0);
    ans[0] = nums.reduce(function (acc, v, i) { return acc + i * v; }, 0);
    ans[n - 1] = ans[0] + total - n * nums[n - 1];
    var max = Math.max(ans[0], ans[n - 1]);
    if (n > 2) {
        for (var i = n - 2; i > 0; i--)
            max = Math.max(max, ans[i] = ans[i + 1] + total - n * nums[i]);
    }
    return max;
}
;
// here i am storing thee factor by which rotation is happening 
// the answer is stored for that in ans[n-k] assume rotate by k factor
// but that's not the demand in question so going to eliminate that
