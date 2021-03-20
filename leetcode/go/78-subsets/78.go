package main

import "fmt"

func subsets(nums []int) [][]int {
	var numSubset [][]int
	numSubset = append(numSubset, []int{})
	for i := 0; i < len(nums); i++ {
		m := len(numSubset)
		for j := 0; j < m; j++ {
			tmp := make([]int, len(numSubset[j]))
			copy(tmp, numSubset[j])
			tmp = append(tmp, nums[i])
			// fmt.Println(tmp, nums[i], i)
			// fmt.Println(tmp, j)
			numSubset = append(numSubset, tmp)
			// fmt.Println(j)
		}
	}
	return numSubset
}

func main() {
	nums := []int{9, 0, 3, 5, 7}

	fmt.Println(subsets(nums))
}
