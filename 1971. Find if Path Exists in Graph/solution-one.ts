type Graph = Readonly<Record<number, number[]>>

const build_graph = (n: number, edges: number[][]): Graph => {
    const graph: Record<number, number[]> = {}

    for (let i = 0; i < n; i++)
        graph[i] = []

    for (const e of edges) {
        let [i, j] = e
        graph[i].push(j)
        graph[j].push(i)
    }

    return graph as Graph
}

const build_graph_matrix = (n: number, edges: number[][]): boolean[][] => {
    let graph: boolean[][] = Array.from({ length: n }, () => Array<boolean>(n).fill(false))
    let i: number = 0, j: number = 0;

    for (const e of edges) {
        [i, j] = e
        graph[i][j] = true, graph[j][i] = true
    }

    return graph
}

const bfs = (graph: Graph, source: number, destination: number) => {
    const queue: number[] = [source]
    const visited: Set<number> = new Set<number>()

    while (queue.length > 0) {
        const node: number = queue.shift()!
        visited.add(node)
        if (node === destination)
            return true
        graph[node].forEach((neighbour: number) => visited.has(neighbour) ? null : queue.push(neighbour))
    }

    return false
}


const dfs = (graph: Graph, source: number, destination: number, visited: Set<number>): boolean => {
    if (source === destination)
        return true

    visited.add(source)
    for (const neighbour of graph[source]) {
        if (!visited.has(neighbour) && dfs(graph, neighbour, destination, visited))
            return true
    }

    return false
}


const dfs_in_graph_matrix = (graph: boolean[][], source: number, destination: number): boolean => {

    if (source === destination)
        return true

    for (let i = 0; i < graph.length; i++) {
        if (graph[source][i]) {
            graph[source][i] = false, graph[i][source] = false
            if (dfs_in_graph_matrix(graph, i, destination))
                return true
        }
    }

    return false

}

function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    return dfs(build_graph(n, edges), source, destination, new Set())
};
