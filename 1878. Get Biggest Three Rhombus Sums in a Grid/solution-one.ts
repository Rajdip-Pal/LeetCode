function getBiggestThree(grid: number[][]): number[] {

    class Answer {
        private val: [number, number, number]
        constructor() { this.val = [0, 0, 0] }
        get() { return Array.from(this.val) as number[] }
        put(x: number) {
            if (x > this.val[0])
                [this.val[2], this.val[1], this.val[0]] = [this.val[1], this.val[0], x]
            else if (x != this.val[0] && x > this.val[1])
                [this.val[2], this.val[1]] = [this.val[1], x]
            else if (x != this.val[0] && x != this.val[1] && x > this.val[2])
                this.val[2] = x
        }
    }

    const ans: Answer = new Answer()

    const rows: number = grid.length
    const cols: number = grid[0].length


    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {

                

        }
    }

    return ans.get()
};


getBiggestThree([[]])
