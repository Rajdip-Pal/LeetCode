function numIslands(grid: string[][]): number {

    let islands: number = 0

    const dfs = (start: [number, number]) => {
        const dx = [0, 0, 1, -1]
        const dy = [1, -1, 0, 0]
        const rows = grid.length
        const cols = grid[0].length

        let nx: number = 0, ny: number = 0;
        const stack: Array<number> = [start[0], start[1]]

        grid[start[0]][start[1]] = '0'
        while (stack.length > 0) {
            const y: number = stack.pop()!
            const x: number = stack.pop()!

            for (let i = 0; i < 4; i++) {
                nx = x + dx[i], ny = y + dy[i]

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] !== '1') { }
                else stack.push(nx, ny), grid[nx][ny] = '0'
            }
        }
    }


    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === '1')
                islands++, dfs([i, j])
        }
    }


    return islands

};

/**
 * 1.   Rather than visited flip the value '1' to '0'
 * 2.   stack can be used as number[] rather than Array<[number, number]>
 *      ->   so if i push in order like x -> y
 *      ->   then needs to be poped like y -> x
 *      -> saves the overhead of creating new objects
 */

console.log(

    numIslands(
        [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
    ),

    numIslands(
        [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
    )

)
