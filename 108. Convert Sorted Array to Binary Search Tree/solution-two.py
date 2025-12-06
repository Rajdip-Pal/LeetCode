# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.__create_BST(nums, 0, len(nums) - 1)

    def __create_BST(self, nums: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None

        mid = left + (right - left) // 2
        node = TreeNode(nums[mid])
        node.left = self.__create_BST(nums, left, mid - 1)
        node.right = self.__create_BST(nums, mid + 1, right)

        return node
