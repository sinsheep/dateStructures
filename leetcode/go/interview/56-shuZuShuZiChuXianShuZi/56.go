package main

import "fmt"

func singleNumbers(nums []int) []int {
	numbers := make([]int, 2)
	var flag int

	for i := 0; i < len(nums); i++ {
		flag ^= nums[i]
	}

	div := 1

	for (div & flag) == 0 {
		div <<= 1
	}
	numbers[0] = 0
	numbers[1] = 0
	for i := 0; i < len(nums); i++ {
		if (div & nums[i]) == 0 {
			numbers[0] ^= nums[i]
		} else {
			numbers[1] ^= nums[i]
		}
	}

	return numbers
}

func main() {

	nums := []int{1, 2, 5, 2}
	fmt.Println(singleNumbers(nums))
}
