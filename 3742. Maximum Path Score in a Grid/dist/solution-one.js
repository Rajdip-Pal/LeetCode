function maxPathScore(grid, k) {
    var _a, _b;
    var m = grid.length;
    var n = (_b = (_a = grid[0]) === null || _a === void 0 ? void 0 : _a.length) !== null && _b !== void 0 ? _b : 0;
    if (m === 0 || n === 0) {
        return -1;
    }
    var maxCost = Math.min(k, m + n - 2);
    var NEG_INF = -(1 << 30);
    var createState = function () { return new Int32Array(maxCost + 1).fill(NEG_INF); };
    var previousRow = Array.from({ length: n }, createState);
    for (var row = 0; row < m; row++) {
        var currentRow = Array.from({ length: n }, createState);
        for (var col = 0; col < n; col++) {
            if (row === 0 && col === 0) {
                currentRow[col][0] = 0;
                continue;
            }
            var value = grid[row][col];
            var cost = value === 0 ? 0 : 1;
            for (var spent = cost; spent <= Math.min(k, row + col); spent++) {
                var best = NEG_INF;
                if (row > 0) {
                    best = Math.max(best, previousRow[col][spent - cost]);
                }
                if (col > 0) {
                    best = Math.max(best, currentRow[col - 1][spent - cost]);
                }
                if (best !== NEG_INF) {
                    currentRow[col][spent] = best + value;
                }
            }
        }
        previousRow = currentRow;
    }
    var answer = NEG_INF;
    for (var spent = 0; spent <= maxCost; spent++) {
        answer = Math.max(answer, previousRow[n - 1][spent]);
    }
    return answer < 0 ? -1 : answer;
}
