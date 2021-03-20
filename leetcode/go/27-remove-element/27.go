package main

import "fmt"

func removeElement(nums []int, val int) int {
	sum := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[sum] = nums[i]
			sum++
		}
	}
	return sum
}

func main() {
	nums := []int{3, 2, 2, 3}

	fmt.Println(removeElement(nums, 2))
}
