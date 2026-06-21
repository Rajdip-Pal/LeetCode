# Definition for a binary tree node.

from pyparsing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root or (not root.left and not root.right):
            return True

        left_depth = self.get_depth(root.left)
        right_depth = self.get_depth(root.right)

        if abs(left_depth - right_depth) > 1:
            return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)

    def get_depth(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0

        left_depth = self.get_depth(node.left)
        right_depth = self.get_depth(node.right)

        return max(left_depth, right_depth) + 1
