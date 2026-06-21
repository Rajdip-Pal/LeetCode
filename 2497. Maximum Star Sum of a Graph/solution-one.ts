function maxStarSum(vals: number[], edges: number[][], k: number): number {
    const graph: number[][] = Array.from({ length: vals.length }, () => new Array());

    for (const edge of edges) {
        graph[edge[0]].push(vals[edge[1]]);
        graph[edge[1]].push(vals[edge[0]]);
    }

    let max_star_sum: number = -Infinity;
    for (let n = 0; n < vals.length; n++) {
        const neighbour_vals = graph[n];
        neighbour_vals.sort((a, b) => b - a);

        let sum = vals[n];
        for (let i = 0; i < Math.min(k, neighbour_vals.length); i++) {
            if (neighbour_vals[i] > 0)
                sum += neighbour_vals[i]
            else break;
        }

        max_star_sum = Math.max(max_star_sum, sum);
    }

    return max_star_sum;
};