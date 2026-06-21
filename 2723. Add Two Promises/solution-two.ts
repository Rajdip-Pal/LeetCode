type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P) {
    return await promise1 + await promise2;
};

const res = addTwoPromises(new Promise(resolve => setTimeout(() => resolve(10), 10000)), Promise.resolve(2)).then(console.log);
