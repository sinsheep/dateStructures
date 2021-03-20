package main

import "fmt"

func maxSubArray(nums []int) int {
	max := nums[0]
	num := nums[0]
	for i := 1; i < len(nums); i++ {
		if num+nums[i] > nums[i] {
			num += nums[i]
		} else {
			num = nums[i]
		}
		if num >= max {
			max = num
		}
	}
	return max
}

func main() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
}
