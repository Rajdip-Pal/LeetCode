function distance(nums: number[]): number[] {
    // step 1 : declaring map to group indexes with same values;
    const mp: Map<number, Array<number>> = new Map();

    // step 2 : grouping indexes with the same values;
    nums.forEach((num, i) => {
        if (!mp.has(num))
            // if value not present insert new entry;
            mp.set(num, new Array());
        mp.get(num)?.push(i);
    })

    // step 3 : declaring result array of same length 
    const res: Array<number> = Array.from({ length: nums.length }, () => 0);

    // for every group formed previously in map
    for (const [_, v] of mp) {

        // Note : the indexes will always be in increasing order 

        // step 4 : generating prefix sum of the indexes holding the same values 
        const prefixSum: Array<number> = v.reduce<Array<number>>((acc, val, i) => { acc.push((acc[i - 1] ?? 0) + val); return acc; }, []);

        // for each value in group
        v.forEach((idx, i) => {

            //  step 5 : calculate | i - j | (accourding to question) for first [0...i-1] elements
            // 
            //  here | i - j | is always  (i-j) cause i > j
            //  in short the prefix sum at i-1 gives us the sum till [0...i-1]
            //  and subtract from i * idx gives the answer directly;
            // 
            //  it will always be postive cause always in increasing order
            const prev = (i * idx - (prefixSum[i - 1] ?? 0));

            // step 6 : calculate | i - j | (accourding to question) for first [i+1...n] elements
            // 
            //  here | i - j | is always  (j-i) cause  j > i
            //  in short the prefix sum at n-1 subtracted by prefix sum at i gives us the sum till [i+1...n]
            //  and subtract by (n-i-1) * idx gives the answer directly;
            // 
            //  it will always be postive cause always in increasing order
            const next = (prefixSum[v.length - 1] - prefixSum[i] - (v.length - i - 1) * idx);

            // step 7 : put the sum of prev and next at correct index
            res[idx] = prev + next;
        })
    }

    // step 8 : return the final result;
    return res;

};