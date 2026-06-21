function findOrder(numCourses: number, prerequisites: number[][]): number[] {

    const graph: readonly number[][] = Array.from({ length: numCourses }, () => [] as number[])
    const in_degree: number[] = Array.from({ length: numCourses }, () => 0)

    for (const [u, v] of prerequisites) graph[u].push(v), in_degree[v]++

    const res: number[] = []
    const queue: number[] = []

    for (let i = 0; i < numCourses; i++) {
        if (in_degree[i] === 0) queue.push(i)
    }

    while (queue.length > 0) {
        const node = queue.shift()!

        res.push(node)

        for (const neighbour of graph[node])
            if (--in_degree[neighbour] === 0) queue.push(neighbour)
    }

    return res.length === numCourses ? res.reverse() : []
};
