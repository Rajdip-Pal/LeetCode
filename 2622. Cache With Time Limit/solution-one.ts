class TimeLimitedCache<K = any, V = any> {
    private cache: Map<K, { value: V, timer: ReturnType<typeof setTimeout> }>

    constructor() {
        this.cache = new Map<K, { value: V, timer: ReturnType<typeof setTimeout> }>()
    }

    set(key: K, value: V, duration: number): boolean {
        if (this.cache.has(key)) {
            clearTimeout(this.cache.get(key)?.timer)
            this.cache.set(key, { value, timer: setTimeout(() => { this.cache.delete(key) }, duration) })
            return true
        } else {
            this.cache.set(key, { value, timer: setTimeout(() => { this.cache.delete(key) }, duration) })
            return false
        }
    }

    get(key: K): V | -1 {
        return this.cache.get(key)?.value ?? -1;
    }

    count(): number {
        return this.cache.size
    }
}


const timeLimitedCache = new TimeLimitedCache()
console.log(
    timeLimitedCache.set(1, 42, 1000),
    timeLimitedCache.get(1),
    timeLimitedCache.count()
)
