function canFinish(numCourses: number, prerequisites: number[][]): boolean {
    const graph: number[][] = Array.from({ length: numCourses }, () => [])

    for (const [u, v] of prerequisites) graph[u].push(v)

    const state = new Array(numCourses).fill(0)
    // 0 = unvisited, 1 = visiting, 2 = done

    const dfs = (node: number): boolean => {
        if (state[node] === 1) return true   // cycle
        if (state[node] === 2) return false  // already checked

        state[node] = 1

        if (graph[node].some((n) => dfs(n)))
            return true

        state[node] = 2
        return false
    }

    for (let i = 0; i < numCourses; i++) {
        if (dfs(i)) return false
    }

    return true
}
