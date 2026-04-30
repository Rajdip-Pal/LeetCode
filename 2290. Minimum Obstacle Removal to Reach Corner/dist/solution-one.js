var obj = { empty: 0, obstacle: 1 };
function minimumObstacles(grid) {
    var _a, _b;
    var m = grid.length;
    var n = (_b = (_a = grid[0]) === null || _a === void 0 ? void 0 : _a.length) !== null && _b !== void 0 ? _b : 0;
    var directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    var dist = Array.from({ length: m }, function () { return Array.from({ length: n }, function () { return Infinity; }); });
    var deque = Array.from({ length: (m * n * 2) + 1 }, function () { return [0, 0]; });
    var head = m * n;
    var tail = m * n;
    dist[0][0] = 0;
    deque[tail] = [0, 0];
    while (head <= tail) {
        var _c = deque[head++], x = _c[0], y = _c[1];
        for (var _i = 0, directions_1 = directions; _i < directions_1.length; _i++) {
            var _d = directions_1[_i], dx = _d[0], dy = _d[1];
            var nextX = x + dx;
            var nextY = y + dy;
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;
            var weight = grid[nextX][nextY] === obj.obstacle ? 1 : 0;
            var nextDist = dist[x][y] + weight;
            if (nextDist >= dist[nextX][nextY])
                continue;
            dist[nextX][nextY] = nextDist;
            if (weight === obj.empty) {
                deque[--head] = [nextX, nextY];
            }
            else {
                deque[++tail] = [nextX, nextY];
            }
        }
    }
    return dist[m - 1][n - 1];
}
console.log(minimumObstacles([[0, 1, 1], [1, 1, 0], [1, 1, 0]]));
