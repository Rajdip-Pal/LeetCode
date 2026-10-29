class _Node {
    val: number
    left: _Node | null
    right: _Node | null
    next: _Node | null
    constructor(val?: number, left?: _Node, right?: _Node, next?: _Node) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
        this.next = (next === undefined ? null : next)
    }
}


function connect(root: _Node | null): _Node | null {
    if (!root) return null;

    let queue: _Node[] = [root];

    while (queue.length) {
        const newQueue: _Node[] = [];
        const n: number = queue.length;

        for (let i = 0; i < n - 1; i++) {
            queue[i].next = queue[i + 1];

            if (queue[i].left)
                newQueue.push(queue[i].left!);
            if (queue[i].right)
                newQueue.push(queue[i].right!);
        }

        if (queue[n - 1].left)
            newQueue.push(queue[n - 1].left!);
        if (queue[n - 1].right)
            newQueue.push(queue[n - 1].right!);

        queue = newQueue;
    }

    return root;
};