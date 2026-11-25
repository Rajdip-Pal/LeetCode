class DList<K, V> {
    public key: K;
    public value: V;

    next: DList<K, V> | null = null;
    prev: DList<K, V> | null = null;

    constructor(key: K, value: V) {
        this.key = key;
        this.value = value;
    }
}


class LRUCache<K, V> {
    private cache: Map<K, DList<K, V>>;
    private capacity: number = 10;

    private head: DList<K, V> = new DList(null as K, null as V);
    private tail: DList<K, V> = new DList(null as K, null as V);

    constructor(capacity: number) {
        this.cache = new Map();

        if (Number.isInteger(capacity) && capacity > 0) {
            this.capacity = capacity;
        }

        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    private detach(n: DList<K, V>) {
        n.prev!.next = n.next;
        n.next!.prev = n.prev;

        n.prev = n.next = null;
    }

    private place_front(n: DList<K, V>) {
        n.next = this.head.next;
        n.prev = this.head;

        this.head.next!.prev = n;
        this.head.next = n;
    }

    public get(key: K): V {
        const node = this.cache.get(key);
        return node ? (this.detach(node), this.place_front(node), node.value) : -1 as V;
    }

    public put(key: K, value: V): void {
        const curr = this.cache.get(key);

        if (curr) {
            curr.value = value;
            this.detach(curr);
            this.place_front(curr);
            return;
        }

        const node = new DList(key, value);
        this.cache.set(key, node);
        this.place_front(node);

        if (this.cache.size > this.capacity) {
            this.cache.delete(this.tail.prev!.key);
            this.detach(this.tail.prev!);
        }
    }
}

