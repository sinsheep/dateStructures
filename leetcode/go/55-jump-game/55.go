package main

import "fmt"

func canJump3(nums []int) bool {

	m := len(nums)
	dp := make([]int, m)
	dp[0] = nums[0] - 1
	for i := 1; i < m-1; i++ {
		if nums[i] >= dp[i-1] {
			dp[i] = nums[i]
		} else {
			dp[i] = dp[i-1]
		}
		dp[i]--
		if dp[i] < 0 {
			return false
		}
	}
	if dp[0] < 0 && m != 1 {
		return false
	}
	return true
}
func canJump2(nums []int) bool {

	if len(nums) == 1 {
		return true
	}
	max := nums[0]
	for i := 0; i < len(nums)-1; i++ {
		max--
		if max < 0 {
			return false
		}
		if nums[i] > max {
			max = nums[i]
		}
	}
	if max < 1 {
		return false
	}
	return true
}

func canJump(nums []int) bool {

	n := 1
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] >= n {
			n = 1
		} else {
			n++
		}
		if i == 0 && n != 1 {
			return false
		}
	}
	return true
}

func main() {

	nums := []int{0, 1}
	fmt.Println(canJump3(nums))
}
