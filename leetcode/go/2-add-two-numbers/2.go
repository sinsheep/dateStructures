package main

/**/
//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var l3, l4 *ListNode
	var num, sum int
	l3 = &ListNode{Val: 0}
	l3.Val = 1
	l4 = l3
	for {
		sum = l1.Val + l2.Val + num
		l4.Val = sum % 10
		num = sum / 10
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
		l4.Next = &ListNode{Val: 0}
		if l1 == nil {
			l4 = l2.Next
			break
		}
		if l2 == nil {
			l4 = l2.Next
			break
		}
		l4 = l4.Next
	}
	return l3
}

func main() {

	var ll, lw *ListNode
	addTwoNumbers(ll, lw)
}
