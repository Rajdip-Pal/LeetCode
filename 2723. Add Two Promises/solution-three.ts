type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P) {
    return Promise.all([promise1, promise2]).then(arr => arr.reduce((a: number, b: number): number => a + b, 0));
};

const res = addTwoPromises(new Promise(resolve => setTimeout(() => resolve(10), 10000)), Promise.resolve(2)).then(console.log);
