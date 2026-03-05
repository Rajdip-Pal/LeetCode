function generateParenthesis(n: number): string[] {
    const res: string[] = []

    const bactrack = function (curr: string = '', insertions: number = 0, completions: number = 0) {
        if ((insertions === n) && (completions === n))
            res.push(curr)
        else {
            if (insertions < n) bactrack(curr + '(', insertions + 1, completions)
            if (insertions > completions) bactrack(curr + ')', insertions, completions + 1)
        }
    }

    bactrack()
    return res
};

console.log(
    generateParenthesis(3)
)
