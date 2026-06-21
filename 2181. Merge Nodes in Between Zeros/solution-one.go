// package main

// //  Definition for singly-linked list.

// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

// func mergeNodes(head *ListNode) *ListNode {
// 	node := head
// 	sum := 0

// 	res := &ListNode{}
// 	dummy := res

// 	for node != nil {
// 		if node.Val != 0 {
// 			sum += node.Val
// 		} else {
// 			dummy.Next = &ListNode{Val: sum, Next: nil}
// 			sum = 0
// 			dummy = dummy.Next
// 		}
// 		node = node.Next
// 	}

// 	// For First Node with val a extra node is created with val 0 we need to cut that also
// 	return res.Next.Next

// }
