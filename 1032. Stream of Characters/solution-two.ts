class Trie {

    nodes: (TrieNode | null)[]

    constructor() {
        this.nodes = Array.from({ length: 26 }, () => null)
    }

    insert_reverse(word: string): void {
        if (word.length < 1) return

        let curr: Trie | TrieNode | null = this
        for (let i = word.length - 1; i >= 0; i--) {
            const idx: number = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { curr.nodes[idx] = new TrieNode() }
            if (i === 0) { curr.nodes[idx].end = true }
            curr = curr?.nodes[idx]
        }
    }

    insert(word: string): void {
        if (word.length < 1) return

        let curr: Trie | TrieNode | null = this
        for (let i = 0; i < word.length; i++) {
            const idx: number = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { curr.nodes[idx] = new TrieNode() }
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

    findAny(word: string): boolean {
        if (word.length < 1) return false

        let curr: Trie | TrieNode | null = this
        for (let i = 0; i < word.length; i++) {
            const idx: number = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!curr.nodes[idx]) { return false }
            curr = curr?.nodes[idx]
            if (curr.end) return true;
        }
        return curr instanceof TrieNode && curr.end === true
    }
}

class TrieNode {
    nodes: (TrieNode | null)[]
    end: boolean

    constructor(end?: boolean) {
        this.nodes = Array.from({ length: 26 }, () => null)
        this.end = end ?? false;
    }
}


class StreamChecker {
    private readonly data: Trie;
    private accQuery: string;

    constructor(words: string[]) {
        this.data = new Trie();
        this.accQuery = "";

        for (const word of words) {
            this.data.insert_reverse(word);
        }
    }

    query(letter: string): boolean {
        this.accQuery = letter + this.accQuery;
        this.accQuery = this.accQuery.slice(0, 201);

        return this.data.findAny(this.accQuery);
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */