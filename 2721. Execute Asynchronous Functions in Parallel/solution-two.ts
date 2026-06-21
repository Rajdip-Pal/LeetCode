type Fn<T> = () => Promise<T>

function promiseAll<T>(functions: Fn<T>[]): Promise<T[]> {
    return new Promise(
        (resolve, reject) => {
            let N = functions.length
            const res: T[] = new Array(N).fill(null)
            let count = 0

            for (let i = 0; i < N; i++) {
                functions[i]().then(
                    (output: T) => {
                        res[i] = output
                        count++;

                        if (count === N)
                            resolve(res)
                    }
                ).catch(
                    (err) => reject(err)
                )
            }
        }
    )
};
