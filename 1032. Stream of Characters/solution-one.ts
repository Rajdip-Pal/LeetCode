class CircularQueue<T> {
    private items: Array<T>;
    private front: number;
    private rear: number;

    private size: number;
    readonly capacity: number;

    constructor(k: number) {
        this.capacity = k;
        this.items = new Array(this.capacity);
        this.front = 0;
        this.rear = -1;
        this.size = 0;
    }

    enQueue(value: T): boolean {
        if (this.isFull()) return false;
        this.items[this.rear = (this.rear + 1) % this.capacity] = value;
        this.size++;
        return true;
    }

    deQueue(): boolean {
        if (this.isEmpty()) return false;
        this.front = (this.front + 1) % this.capacity;
        this.size--;
        return true;
    }

    Front(): T | undefined {
        if (this.isEmpty()) return undefined;
        return this.items[this.front];
    }

    Rear(): T | undefined {
        if (this.isEmpty()) return undefined;
        return this.items[this.rear];
    }

    isEmpty(): boolean {
        return this.size === 0;
    }

    isFull(): boolean {
        return this.size === this.capacity;
    }

    length(): number {
        return this.size;
    }
}

class Trie {

    nodes: (TrieNode | null)[]

    constructor() {
        this.nodes = Array.from({ length: 26 }, () => null)
    }

    insert(word: string): void {
        if (word.length < 1) return

        let curr: Trie | TrieNode | null = this
        for (let i = 0; i < word.length; i++) {
            const idx: number = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { curr.nodes[idx] = new TrieNode(word[i], i === word.length - 1 ? true : false) }
            if (i === word.length - 1) { curr.nodes[idx].end = true }
            curr = curr?.nodes[idx]
        }
    }

    search(word: string): boolean {
        if (word.length < 1) return false

        let curr: Trie | TrieNode | null = this
        for (let i = 0; i < word.length; i++) {
            const idx: number = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { return false }
            curr = curr?.nodes[idx]
        }
        return curr instanceof TrieNode && curr.end === true
    }

    startsWith(prefix: string): boolean {
        if (prefix.length < 1) return false

        let curr: Trie | TrieNode | null = this
        for (let i = 0; i < prefix.length; i++) {
            const idx: number = prefix[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { return false }
            curr = curr?.nodes[idx]
        }
        return true
    }
}

class TrieNode {
    letter: string
    nodes: (TrieNode | null)[]
    end: boolean

    constructor(c: string, end: boolean) {
        this.letter = c
        this.nodes = Array.from({ length: 26 }, () => null)
        this.end = end
    }
}


class StreamChecker {
    private nodes: CircularQueue<TrieNode>;
    private readonly data: Trie;

    constructor(words: string[]) {
        this.data = new Trie();

        for (const word of words) {
            this.data.insert(word);
        }

        this.nodes = new CircularQueue(words.length);
    }

    query(letter: string): boolean {

        let flag: boolean = false;
        const length: number = this.nodes.length();

        for (let i = 0; i < length; i++) {
            const node = this.nodes.Front();
            this.nodes.deQueue();

            const next = node?.nodes[letter.charCodeAt(0) - 'a'.charCodeAt(0)];
            if (next) {
                this.nodes.enQueue(next);
                if (next.end) flag = true;
            }
        }

        const rootNext = this.data.nodes[letter.charCodeAt(0) - 'a'.charCodeAt(0)];
        if (rootNext) {
            this.nodes.enQueue(rootNext);
        }

        return rootNext?.end || flag;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */