function minMutation(
    startGene: string,
    endGene: string,
    bank: string[]
): number {
    // Include unique genes
    const validGenes = [...new Set([startGene, ...bank])];
    const n = validGenes.length;

    const src = validGenes.indexOf(startGene);
    const dest = validGenes.indexOf(endGene);

    // Every mutation must change exactly one character
    function countMutation(gene1: string, gene2: string): number {
        let count = 0;

        for (let i = 0; i < gene1.length; i++) {
            if (gene1[i] !== gene2[i]) count++;
        }

        return count;
    }

    // Build the cost matrix: only one-character changes are valid edges
    const cost: number[][] = Array.from(
        { length: n },
        (_, i) => Array.from({ length: n }, (_, j) =>
            i !== j && countMutation(validGenes[i], validGenes[j]) === 1
                ? 1
                : Infinity
        )
    );

    // Dijkstra's algorithm
    const dist = new Array(n).fill(Infinity);
    const visited = new Array(n).fill(false);

    dist[src] = 0;

    for (let step = 0; step < n; step++) {
        let u = -1;

        // Find the unvisited node with minimum distance
        for (let i = 0; i < n; i++) {
            if (
                !visited[i] &&
                (u === -1 || dist[i] < dist[u])
            ) {
                u = i;
            }
        }

        // Destination is unreachable
        if (u === -1 || dist[u] === Infinity) break;

        // Shortest distance to destination is finalized
        if (u === dest) return dist[u];

        visited[u] = true;

        // Relax all neighboring genes
        for (let v = 0; v < n; v++) {
            if (
                !visited[v] &&
                cost[u][v] !== Infinity &&
                dist[u] + cost[u][v] < dist[v]
            ) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    return -1;
}