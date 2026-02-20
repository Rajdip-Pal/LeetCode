function createCounter(n: number): () => number {
    let count: typeof n = n

    return function (): typeof n {
        return n++
    }
}
