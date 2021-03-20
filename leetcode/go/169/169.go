package main

import (
	"fmt"
	"sort"
)

func majorityElementEasy(nums []int) int {

	sort.Ints(nums)
	return nums[len(nums)/2]
}
func majorityElement(nums []int) int {
	var maxNum, count int
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			maxNum = nums[i]
		}
		if maxNum == nums[i] {
			count++
		} else {
			count--
		}
	}
	return maxNum
}

func main() {

	nums := []int{2, 1, 1, 1, 1, 2, 2}

	fmt.Println(majorityElement(nums))
	fmt.Println(majorityElementEasy(nums))
}
