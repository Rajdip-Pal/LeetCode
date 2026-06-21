type F = (...args: number[]) => void

// function debounce(fn: F, t: number): F {
//     let timer: ReturnType<typeof setTimeout>;

//     return function (...args: number[]) {
//         clearTimeout(timer);
//         timer = setTimeout(() => {
//             fn(...args);
//         }, t);
//     } as F;

// };

function advanceDebounce(fn: F, t: number): F {
    let timer: ReturnType<typeof setTimeout>;

    return function (...args: number[]) {
        clearTimeout(timer);
        timer = setTimeout(() => {
            fn.apply(null, args);
        }, t);
    } as F;

};

function debounce<T extends (...args: any[]) => void>(fn: T, t: number): T {
    let timer: ReturnType<typeof setTimeout>;

    return function (this: ThisParameterType<T>, ...args: Parameters<T>) {
        clearTimeout(timer);
        timer = setTimeout(() => {
            fn.apply(this, args);
        }, t);
    } as T;
}

// usage
const debouncedLog = debounce(console.log, 1000);

debouncedLog("Hello, World!"); // Logs "Hello, World!" after 1 second
debouncedLog("Hello, TypeScript!"); // Cancels previous log and logs "Hello, TypeScript!" after 1 second
debouncedLog("Hello, Debounce!"); // Cancels previous log and logs "Hello, Debounce!" after 1 second

debouncedLog(15)

const obj = { x: 42, logX() { console.log(this.x); } };

const debouncedLogX = debounce(obj.logX, 1000);

debouncedLogX.call(obj); // Logs 42 after 1 second

const advanceDebounceLogX = advanceDebounce(obj.logX, 1000);

advanceDebounceLogX.call(obj); // Logs 42 after 1 second
