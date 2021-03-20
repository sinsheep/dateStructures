package main

// * Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {

	if p.Val != q.Val {
		return false
	}
	for {
		if p.Left == nil || q.Left == nil || q.Right == nil || p.Right == nil {
			break
		}
		isSameTree()
	}
	return true
}
func main() {

}
