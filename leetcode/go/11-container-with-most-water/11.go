package main

import (
	"fmt"
)

func maxArea(height []int) int {

	secondIndex, firstIndex := len(height)-1, 0
	maxValue := 0
	for {

		if secondIndex <= firstIndex {
			break
		}
		var num int
		lens := secondIndex - firstIndex
		if height[secondIndex] > height[firstIndex] {
			num = height[firstIndex]
			firstIndex++
		} else {
			num = height[secondIndex]
			secondIndex--
		}
		if maxValue < lens*num {
			maxValue = lens * num
		}
	}
	return maxValue
}
func main() {

	nums := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}

	fmt.Println(maxArea(nums))
}
