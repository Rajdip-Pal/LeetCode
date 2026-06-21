function isMatch(s: string, p: string) {

    const cache: Map<string, boolean> = new Map()

    function dfs(ptr_s: number, ptr_p: number): boolean {
        const key: string = JSON.stringify([ptr_s, ptr_p])
        if (cache.has(key))
            return cache.get(key)!

        if (ptr_s >= s.length && ptr_p >= p.length) return true
        if (ptr_p >= p.length) return false

        const match: boolean = (ptr_s < s.length) && (s[ptr_s] === p[ptr_p] || p[ptr_p] === '.')

        if (ptr_p + 1 < p.length && p[ptr_p + 1] === '*') {
            cache.set(key, dfs(ptr_s, ptr_p + 2) || (match && dfs(ptr_s + 1, ptr_p)))
            return cache.get(key)!
        }

        if (match) {
            cache.set(key, dfs(ptr_s + 1, ptr_p + 1))
            return cache.get(key)!
        }

        cache.set(key, false)
        return cache.get(key)!
    }

    return dfs(0, 0)
};
