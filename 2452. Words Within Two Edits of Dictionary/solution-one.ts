class TrieNode {
    child: (TrieNode | null)[] = Array.from({ length: 26 }, () => null);
    isEnd: boolean = false;
}

class Trie {
    root: TrieNode = new TrieNode();

    insert(w: Lowercase<string>) {
        let parent: TrieNode = this.root;

        for (let index = 0; index < w.length; index++) {
            const idx: number = w.charCodeAt(index) - 'a'.charCodeAt(0);
            if (!parent.child[idx])
                parent.child[idx] = new TrieNode();
            parent = parent.child[idx];
        }

        parent.isEnd = true;
    }

    has(w: Lowercase<string>, maxError: number = 0) {
        const dfs = (w_idx: number, root: TrieNode, error: number) => {
            if (w_idx === w.length) return root.isEnd;

            const idx = w.charCodeAt(w_idx) - 'a'.charCodeAt(0);
            if (root.child[idx] && dfs(w_idx + 1, root.child[idx], error))
                return true;

            if (error < maxError) {
                for (let index = 0; index < 26; index++) {
                    if (idx === index) continue;
                    if (root.child[index] && dfs(w_idx + 1, root.child[index]!, error + 1))
                        return true;
                }
            }

            return false;
        }

        return dfs(0, this.root, 0);
    }
}

function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const trieRoot = new Trie();
    const res: string[] = [];

    for (const w of dictionary)
        trieRoot.insert(w as Lowercase<string>);

    for (const q of queries)
        if (trieRoot.has(q as Lowercase<string>, 2))
            res.push(q);

    return res;
};