package main

//  Definition for singly-linked list.

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeNodes(head *ListNode) *ListNode {
	res := &ListNode{}
	dummy := res

	for head.Next != nil {
		if head.Val != 0 {
			dummy.Val += head.Val
		} else {
			dummy.Next = &ListNode{}
			dummy = dummy.Next
		}
		head = head.Next
	}

	// For First Node with val a extra node is created with val 0 we need to cut that also
	return res.Next

}
