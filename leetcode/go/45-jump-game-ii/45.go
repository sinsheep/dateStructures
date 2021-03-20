package main

import "fmt"

func jump(nums []int) int {
	l := 0
	end := 0
	maxl := 0
	for i := 0; i < len(nums); i++ {
		if nums[i]+i > maxl {
			maxl = nums[i] + i
		}
		if i == end {
			end = maxl
			l++
		}
	}
	return l
}

func main() {

	fmt.Println(jump([]int{2, 1}))

}
