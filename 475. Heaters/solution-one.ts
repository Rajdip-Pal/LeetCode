function findRadius(houses: number[], heaters: number[]): number {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);

    const check = (radius: number) => {

        let i: number = 0, j: number = 0;
        while (i < houses.length && j < heaters.length) {
            if (heaters[j] - radius > houses[i]) return false;

            if (heaters[j] + radius >= houses[i]) i++;
            else j++;
        }

        return i === houses.length;
    }

    let l: number = 0, r: number = 1e9 + 1;
    let ans: number = 0;

    while (l <= r) {
        const mid = l + ((r - l) >>> 1);

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
};