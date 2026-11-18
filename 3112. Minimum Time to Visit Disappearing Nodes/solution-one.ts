function minimumTime(n: number, edges: number[][], disappear: number[]): number[] {
    edges.sort((a, b) => {
        return a[0] === b[0] ? a[1] - b[1] : a[0] - b[0];
    })

    const dist = Array.from({ length: n }, () => Infinity);
    dist[0] = 0;

    for (const [u, v, l] of edges) {
        if (dist[u] + l < dist[v])
            dist[v] = dist[u] + l;
    }

    console.log(dist);

    return [0];
};