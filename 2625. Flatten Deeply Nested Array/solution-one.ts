type MultiDimensionalArray = (number | MultiDimensionalArray)[];

const flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {

    const res: MultiDimensionalArray = [];

    const helper = (arr: MultiDimensionalArray, n: number) => {
        for (const item of arr) {
            if (Array.isArray(item) && n > 0) {
                helper(item, n - 1);
            } else {
                res.push(item);
            }
        }
    };

    helper(arr, n);
    return res;
};
