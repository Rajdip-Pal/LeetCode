# Definition for a binary tree node.
from typing import Optional
from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:

        res = 0

        def isPalindromePossible(map: defaultdict[bool]) -> bool:
            n = 0
            for i in range(1, 10):
                n += map[i]
                if n > 1:
                    return False

            return True

        def treeTraversal(root: TreeNode, map: defaultdict[bool]):
            nonlocal res

            # 1 -> for odd
            # 0 -> for even
            map[root.val] = not map[root.val]

            if not root.left and not root.right:
                res += 1 if isPalindromePossible(map) else 0
                map[root.val] = not map[root.val]
                return

            if root.left:
                treeTraversal(root.left, map)

            if root.right:
                treeTraversal(root.right, map)

            map[root.val] = not map[root.val]

        treeTraversal(root, defaultdict(int))

        return res
