type Fn = (...params: any) => any

class LookupNode {
    children: Map<any, LookupNode>;
    value: any;
    hasValue: boolean;

    constructor() {
        this.children = new Map();
        this.hasValue = false;
        this.value = undefined;
    }
}

class LookupTree {
    root: LookupNode;

    constructor() {
        this.root = new LookupNode();
    }

    get(path: any[]) {
        let node = this.root;

        for (let key of path) {
            if (!node.children.has(key)) {
                return { success: false, value: undefined };
            }
            node = node.children.get(key)!;
        }

        if (node.hasValue) {
            return { success: true, value: node.value };
        }

        return { success: false, value: undefined };
    }

    set(path: any[], value: any) {
        let node = this.root;

        for (let key of path) {
            if (!node.children.has(key)) {
                node.children.set(key, new LookupNode());
            }
            node = node.children.get(key)!;
        }

        node.value = value;
        node.hasValue = true;
    }
}

function memoize(fn: Fn): Function {

    const tree = new LookupTree();

    return function (...args: any[]) {
        const { success, value } = tree.get(args);

        if (success) {
            return value;
        }

        const result = fn(...args);
        tree.set(args, result);
        return result;
    };
}
