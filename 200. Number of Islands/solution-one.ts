function numIslands(grid: string[][]): number {

    let islands: number = 0
    let visited: boolean[][] = Array.from({ length: grid.length }, () => new Array<boolean>(grid[0].length).fill(false))

    const dfs = (start: [number, number]) => {
        const stack: Array<[number, number]> = [start]
        const dx = [0, 0, 1, -1]
        const dy = [1, -1, 0, 0]

        visited[start[0]][start[1]] = true
        while (stack.length > 0) {
            const node: [number, number] = stack.pop()!

            for (let i = 0; i < 4; i++) {
                const [nx, ny] = [node[0] + dx[i], node[1] + dy[i]]
                if ((nx >= 0 && nx < grid.length) && (ny >= 0 && ny < grid[0].length))
                    if (!visited[nx][ny] && grid[nx][ny] === '1')
                        visited[nx][ny] = true, stack.push([nx, ny])

            }
        }
    }


    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (!visited[i][j] && grid[i][j] === '1')
                islands++, dfs([i, j])
        }
    }


    return islands

};

console.log(

    numIslands(
        [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
    ),

    numIslands(
        [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
    )

)
