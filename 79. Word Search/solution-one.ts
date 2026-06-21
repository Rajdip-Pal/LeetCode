function exist(board: string[][], word: string): boolean {
    const rows = board.length
    const cols = board[0].length

    const word_chars = word.split('');

    const ds = [0, 1, 0, -1, 0]

    const isValidNode = (x: number, y: number): boolean => !(x < 0 || x >= rows || y < 0 || y >= cols)

    const dfs = (x: number, y: number, w_idx: number): boolean => {
        if (w_idx === word_chars.length) return true

        const temp = board[x][y]
        board[x][y] = '#'

        let nx: number = 0, ny: number = 0;

        for (let i = 0; i < 4; i++) {
            nx = x + ds[i]
            ny = y + ds[i + 1]

            if (isValidNode(nx, ny) && board[nx][ny] === word_chars[w_idx]) {
                if (dfs(nx, ny, w_idx + 1) === true)
                    return true
            }

        }

        board[x][y] = temp
        return false
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] === word_chars[0] && dfs(i, j, 1) === true) return true
        }
    }

    return false

};
