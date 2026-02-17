type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    const flatten: number[] = []

    const helper = (value: MultidimensionalArray | number): void => {
        if (Array.isArray(value))
            for (const item of value) helper(item)
        else flatten.push(value)
    }

    helper(arr)

    yield* flatten

};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
