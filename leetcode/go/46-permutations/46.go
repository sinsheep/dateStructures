package main

import "fmt"

var nlen int

func dfs(num []int, nums *[][]int, tmp []int) {

	l := len(num)
	if l == 1 {
		tmp = append(tmp, num[0])
		*nums = append((*nums), tmp)
		return
	}
	for i := 0; i < l; i++ {
		num[i], num[0] = num[0], num[i]
		dfs(num[1:], nums, append(tmp, num[0]))
		num[0], num[i] = num[i], num[0]
	}
}
func permute(nums []int) [][]int {

	var num [][]int
	nlen = len(nums)
	if nlen == 0 {
		return num
	}
	dfs(nums, &num, nil)
	return num
}

func main() {

	fmt.Println(permute([]int{1, 2, 3}))
}
