package main

import (
	"fmt"
)

func repeatedNTimes(A []int) int {
	var mp [10001]int
	for _, value := range A {
		mp[value]++
		if mp[value] > 1 {
			return value
		}
	}
	return -1
}

func main() {

	fmt.Println(repeatedNTimes([]int{2, 1, 2, 5, 3, 2}))
}
