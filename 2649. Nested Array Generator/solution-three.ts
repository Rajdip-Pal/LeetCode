type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {

    const helper = (value: MultidimensionalArray | number): number[] => {
        const res: number[] = []
        const stack: MultidimensionalArray = Array.from(arr).reverse()

        while (stack.length > 0) {
            let n = stack.pop()!
            if (Array.isArray(n)) for (const item of n.reverse()) stack.push(item)
            else res.push(n)
        }

        return res;
    }

    const flatten: number[] = helper(arr)

    yield* flatten

};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
