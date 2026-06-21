from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorder(self, root: Optional[TreeNode], nodes: List[TreeNode]) -> None:
        if not root:
            return
        else:
            self.inorder(root.left, nodes)
            nodes.append(root)
            self.inorder(root.right, nodes)

    def buildBST(self, nodes: List[TreeNode], left: int, right: int) -> Optional[TreeNode]:
        if not nodes or left > right:
            return None
        else:
            mid = (left + right) // 2
            root = nodes[mid]
            root.left = self.buildBST(nodes, left, mid - 1)
            root.right = self.buildBST(nodes, mid + 1, right)

            return root

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nodes = []
        self.inorder(root, nodes)
        return self.buildBST(nodes, 0, len(nodes) - 1)
