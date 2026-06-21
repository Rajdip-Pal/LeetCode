type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P) {
    const [num1, num2] = await Promise.all([promise1, promise2]);
    return num1 + num2;
};

const res = addTwoPromises(new Promise(resolve => setTimeout(() => resolve(10), 10000)), Promise.resolve(2)).then(console.log);
