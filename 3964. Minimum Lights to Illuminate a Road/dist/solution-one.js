function minLights(lights) {
    var n = lights.length;
    var isIluminated = new Array(n).fill(false);
    var x = 0;
    for (var i = 0; i < n; i++) {
        if (lights[i] > 0)
            x = Math.max(x, lights[i]);
        if (x > 0) {
            isIluminated[i] = true;
            x--;
        }
    }
    for (var i = 0; i < n; i++) {
        if (lights[i] > 0)
            x = Math.max(x, lights[i]);
        if (x > 0) {
            isIluminated[i] = true;
            x--;
        }
    }
}
;
