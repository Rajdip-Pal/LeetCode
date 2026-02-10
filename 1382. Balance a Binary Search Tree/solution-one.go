// Definition for a binary tree node.
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderList(root *TreeNode, list *[]*TreeNode) {
	if root == nil {
		return
	}
	inorderList(root.Left, list)
	*list = append(*list, root)
	inorderList(root.Right, list)
}

func buildBST(list []*TreeNode, left, right int) *TreeNode {
	if left > right {
		return nil
	}
	mid := left + (right-left)/2
	root := list[mid]
	root.Left = buildBST(list, left, mid-1)
	root.Right = buildBST(list, mid+1, right)
	return root
}

func balanceBST(root *TreeNode) *TreeNode {
	var list []*TreeNode
	inorderList(root, &list)
	return buildBST(list, 0, len(list)-1)
}
