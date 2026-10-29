class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


function printTree(root: TreeNode | null): string[][] {
    function binary_tree_height(root: TreeNode | null, h: number = 0): number {
        if (!root) return h - 1;

        const left: number = binary_tree_height(root.left, h + 1);
        const right: number = binary_tree_height(root.right, h + 1);

        return Math.max(left, right);
    }

    const h = binary_tree_height(root);
    const m = h + 1;
    const n = (1 << (h + 1)) - 1;

    const res: string[][] = Array.from({ length: m }, () => new Array(n).fill(""))

    function put_value_in_place(root: TreeNode | null, level: number = 0, start: number = 0, end: number = n - 1) {
        if (!root)
            return;

        const pos: number = start + (end - start) / 2;

        put_value_in_place(root.left, level + 1, start, pos - 1);
        res[level][pos] = root.val.toString();
        put_value_in_place(root.right, level + 1, pos + 1, end);
    }

    put_value_in_place(root);
    return res;
};