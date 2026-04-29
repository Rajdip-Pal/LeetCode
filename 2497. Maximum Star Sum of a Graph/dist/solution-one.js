function maxStarSum(vals, edges, k) {
    var graph = Array.from({ length: vals.length }, function () { return new Array(); });
    for (var _i = 0, edges_1 = edges; _i < edges_1.length; _i++) {
        var edge = edges_1[_i];
        graph[edge[0]].push(vals[edge[1]]);
        graph[edge[1]].push(vals[edge[0]]);
    }
    var max_star_sum = -Infinity;
    for (var n = 0; n < vals.length; n++) {
        var neighbour_vals = graph[n];
        neighbour_vals.sort(function (a, b) { return b - a; });
        var sum = vals[n];
        for (var i = 0; i < Math.min(k, neighbour_vals.length); i++) {
            if (neighbour_vals[i] > 0)
                sum += neighbour_vals[i];
            else
                break;
        }
        max_star_sum = Math.max(max_star_sum, sum);
    }
    return max_star_sum;
}
;
