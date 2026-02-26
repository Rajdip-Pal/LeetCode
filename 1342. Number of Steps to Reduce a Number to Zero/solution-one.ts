function numberOfSteps(num: number): number {

    let steps: number = 0

    while (num > 0)
        steps++, (num & 1) ? num-- : num >>= 1

    return steps

};
