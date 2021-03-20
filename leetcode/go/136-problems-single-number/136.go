package main

import "fmt"

func singleNumber(nums []int) int {
	a := 0
	for _, v := range nums {
		a ^= v
	}
	return a
}

func main() {

	nums := []int{1, 1, 3}
	fmt.Println(singleNumber(nums))
}
