function findCircleNum(isConnected: number[][]): number {

    let count = 0;
    let visited: Array<boolean> = new Array<boolean>(isConnected.length).fill(false)

    const dfs = (start: number) => {
        const stack = [start]

        visited[start] = true
        while (stack.length > 0) {
            const node = stack.pop()!

            for (let neighbour: number = 0; neighbour < isConnected[node].length; neighbour++)
                if (isConnected[node][neighbour] === 1 && !visited[neighbour])
                    stack.push(neighbour), visited[neighbour] = true
        }
    }


    for (let i = 0; i < isConnected.length; i++) {
        if (!visited[i])
            count++, dfs(i)
    }

    return count;

};
