type Entry<K, V> = {
    key: K;
    value: V;
    next?: Entry<K, V>;
};

export class HashMap<K, V> implements Map<K, V> {
    private buckets: Array<Entry<K, V> | undefined>;
    private _size = 0;
    private capacity: number;

    private readonly LOAD_FACTOR = 0.75;

    constructor(initialCapacity = 16) {
        this.capacity = this.nextPowerOfTwo(initialCapacity);
        this.buckets = new Array(this.capacity);
    }

    get size(): number {
        return this._size;
    }

    private nextPowerOfTwo(n: number): number {
        let p = 1;
        while (p < n) p <<= 1;
        return p;
    }

    private hash(key: K): number {
        const str = typeof key === "string"
            ? key
            : JSON.stringify(key);

        // FNV-1a 32-bit
        let hash = 2166136261;
        for (let i = 0; i < str.length; i++) {
            hash ^= str.charCodeAt(i);
            hash = Math.imul(hash, 16777619);
        }

        return hash >>> 0;
    }

    private index(hash: number): number {
        return hash & (this.capacity - 1);
    }

    private resize() {
        const oldBuckets = this.buckets;
        this.capacity <<= 1;
        this.buckets = new Array(this.capacity);
        this._size = 0;

        for (const bucket of oldBuckets) {
            let current = bucket;
            while (current) {
                this.set(current.key, current.value);
                current = current.next;
            }
        }
    }

    set(key: K, value: V): this {
        if (this._size / this.capacity >= this.LOAD_FACTOR) {
            this.resize();
        }

        const hash = this.hash(key);
        const idx = this.index(hash);

        let current = this.buckets[idx];

        if (!current) {
            this.buckets[idx] = { key, value };
            this._size++;
            return this;
        }

        while (true) {
            if (Object.is(current.key, key)) {
                current.value = value;
                return this;
            }

            if (!current.next) break;
            current = current.next;
        }

        current.next = { key, value };
        this._size++;
        return this;
    }

    get(key: K): V | undefined {
        const hash = this.hash(key);
        const idx = this.index(hash);

        let current = this.buckets[idx];
        while (current) {
            if (Object.is(current.key, key)) {
                return current.value;
            }
            current = current.next;
        }

        return undefined;
    }

    has(key: K): boolean {
        const hash = this.hash(key);
        const idx = this.index(hash);

        let current = this.buckets[idx];
        while (current) {
            if (Object.is(current.key, key)) {
                return true;
            }
            current = current.next;
        }

        return false;
    }

    delete(key: K): boolean {
        const hash = this.hash(key);
        const idx = this.index(hash);

        let current = this.buckets[idx];
        let prev: Entry<K, V> | undefined;

        while (current) {
            if (Object.is(current.key, key)) {
                if (prev) {
                    prev.next = current.next;
                } else {
                    this.buckets[idx] = current.next;
                }
                this._size--;
                return true;
            }

            prev = current;
            current = current.next;
        }

        return false;
    }

    clear(): void {
        this.buckets = new Array(this.capacity);
        this._size = 0;
    }

    *entries(): IterableIterator<[K, V]> {
        for (const bucket of this.buckets) {
            let current = bucket;
            while (current) {
                yield [current.key, current.value];
                current = current.next;
            }
        }
    }

    *keys(): IterableIterator<K> {
        for (const [k] of this.entries()) {
            yield k;
        }
    }

    *values(): IterableIterator<V> {
        for (const [, v] of this.entries()) {
            yield v;
        }
    }

    forEach(
        callbackfn: (value: V, key: K, map: Map<K, V>) => void,
        thisArg?: any
    ): void {
        for (const [k, v] of this.entries()) {
            callbackfn.call(thisArg, v, k, this);
        }
    }

    [Symbol.iterator](): IterableIterator<[K, V]> {
        return this.entries();
    }

    get [Symbol.toStringTag](): string {
        return "HashMap";
    }
}

//  check performance difference between Map and HashMap
// check performance difference between Map and HashMap with 100000 entries
const largeMap = new HashMap<number, number>();
const largeMap2 = new Map<number, number>();

for (let i = 0; i < 100000; i++) {
    largeMap.set(i, i);
    largeMap2.set(i, i);
}

console.time("Map get");
for (let i = 0; i < 100000; i++) {
    largeMap2.get(i);
}
console.timeEnd("Map get");

console.time("HashMap get");
for (let i = 0; i < 100000; i++) {
    largeMap.get(i);
}
console.timeEnd("HashMap get");


// still scopes to improve performance in Hashmap
// 1. optimize hash function for numbers
// 2. use open addressing instead of separate chaining
// 3. implement a more efficient resizing strategy (e.g., incremental resizing)
// 4. use a more compact data structure for entries (e.g., array of keys and values instead of linked list)
// 5. implement a more efficient collision resolution strategy (e.g., Robin Hood hashing)
// 6. use a more efficient way to handle deleted entries (e.g., tombstones)
