function permute(nums: number[]): number[][] {
    const res: number[][] = [];
    const used: boolean[] = new Array(nums.length).fill(false);

    function dfs(path: number[]) {
        if (path.length === nums.length) {
            res.push([...path]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push(nums[i]);

            dfs(path);

            path.pop();
            used[i] = false;
        }
    }

    dfs([]);
    return res;
}

function getPermutation(n: number, k: number): string {
    const p = permute(new Array(n).fill(-1).map((_, i) => i + 1));
    return p[k - 1].join('');
};