function minPartitions(n: string): number {
    let max_digit: number = 1;
    const arr: string[] = n.split('');

    for (let i = 0; i < arr.length; i++) {
        max_digit = Math.max(max_digit, Number(arr[i]))
    }

    return max_digit
};
