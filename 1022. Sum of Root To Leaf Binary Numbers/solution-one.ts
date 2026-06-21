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


function sumRootToLeaf(root: TreeNode | null): number {
    let res: number = 0;

    const dfs = (root: TreeNode | null, path: string = '0') => {
        if (root) {
            path += root.val
            if (!root.left && !root.right)
                res += parseInt(path, 2)
            else
                dfs(root.left, path), dfs(root.right, path)
        }
    }

    dfs(root)

    return res
};
