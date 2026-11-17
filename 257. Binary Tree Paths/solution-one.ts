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


function binaryTreePaths(root: TreeNode | null, path: string = "", result: string[] = []): string[] {
    if (!root) {
        return result;
    }

    path = path + root.val + "->";
    if (root.left) binaryTreePaths(root.left, path, result);
    if (root.right) binaryTreePaths(root.right, path, result);

    if (!root.left && !root.right) {
        result.push(path.slice(0, -2));
    }

    return result;
};