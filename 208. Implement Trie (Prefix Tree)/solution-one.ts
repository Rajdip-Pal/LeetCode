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
