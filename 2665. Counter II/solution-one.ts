type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    let val: number = init;

    return {
        increment: () => ++val,
        decrement: () => --val,
        reset: () => val = init
    }
};
