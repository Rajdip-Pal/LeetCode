class Trie {
    nodes: Record<string, Trie>

    constructor(private end: boolean = false) {
        this.nodes = {}
    }

    static ascii(c: string) { return c.charCodeAt(0); }
    private mark_end() { this.end = true; }

    insert(word: string): void {
        if (word.length < 1) return;

        let curr: Trie = this
        for (let i = 0; i < word.length; i++) {
            if (!curr.nodes[word[i]]) curr.nodes[word[i]] = new Trie();
            if (i === (word.length - 1)) curr.nodes[word[i]].mark_end();
            curr = curr.nodes[word[i]];
        }
    }

    search(word: string): boolean {
        if (word.length < 1) return false

        let curr: Trie = this
        for (let i = 0; i < word.length; i++) {
            if (!curr.nodes[word[i]]) return false;
            curr = curr.nodes[word[i]];
        }

        return curr.end;
    }

    pattern(word: string, pos: number = 0, node: Trie = this): boolean {
        if (word.length < 1) return false;
        if (pos === word.length) return node.end;

        if (word.charAt(pos) === ".") {
            for (const n of Object.values(node.nodes))
                if (n && this.pattern(word, pos + 1, n)) return true;
        } else {
            const next = node.nodes[word[pos]];
            if (next)
                return this.pattern(word, pos + 1, next);
        }

        return false;
    }

    startsWith(prefix: string): boolean {
        if (prefix.length < 1) return false

        let curr: Trie = this
        for (let i = 0; i < prefix.length; i++) {
            if (!curr.nodes[prefix[i]]) return false;
            curr = curr.nodes[prefix[i]];
        }

        return true
    }
}

class WordDictionary {
    dict: Trie;

    constructor() {
        this.dict = new Trie();
    }

    addWord(word: string): void {
        this.dict.insert(word);
    }

    search(word: string): boolean {
        return this.dict.pattern(word);
    }
}