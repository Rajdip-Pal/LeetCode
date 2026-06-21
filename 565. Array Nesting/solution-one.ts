function arrayNesting(nums: number[]): number {
    const n = nums.length;
    const visited: boolean[] = new Array(n).fill(false);

    const dfs = (idx: number, depth: number = 0) => {
        if (visited[idx])
            return depth;
        visited[idx] = true;
        return dfs(nums[idx], depth + 1);
    }

    let ans: number = 0;
    for (let i = 0; i < n; i++)
        if (!visited[i]) ans = Math.max(ans, dfs(i));

    return ans;
};