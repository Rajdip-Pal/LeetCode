type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {

    const memory: Map<string, number> = new Map<string, number>()

    return function (...args) {
        const key: string = JSON.stringify(args);

        if (!memory.has(key))
            memory.set(key, fn(...args))

        return memory.get(key)!
    }
}


let callCount = 0;
const memoizedFn = memoize(
    function (a, b) {
        callCount += 1;
        return a + b
    }
)
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3))// 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5
console.log(memoizedFn(2, 3)) // 5

console.log(callCount) // 1
