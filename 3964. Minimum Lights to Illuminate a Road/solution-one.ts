function minLights(lights: number[]): number {

    const n: number = lights.length;
    const isIluminated: boolean[] = new Array(n).fill(false);

    let x: number = 0;
    for (let i = 0; i < n; i++) {
        if (lights[i] > 0) x = Math.max(x, lights[i] + 1); // + 1 because it will illuminate the position itself also
        if (x > 0) {
            isIluminated[i] = true;
            x--;
        }
    }

    for (let i = n - 1; i >= 0; i--) {
        if (lights[i] > 0) x = Math.max(x, lights[i] + 1);
        if (x > 0) {
            isIluminated[i] = true;
            x--;
        }
    }

    let result: number = 0;

    for (let i = 0; i < n; i++) {
        if (!isIluminated[i]) {
            let groupLength: number = 0;
            while (i < n && !isIluminated[i]) { groupLength++; i++; }
            result += Math.ceil(groupLength / 3);
        }
    }

    return result;
};