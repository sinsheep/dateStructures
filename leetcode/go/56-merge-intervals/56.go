package main

import (
	"fmt"
	"sort"
)

func merge(intervals [][]int) [][]int {

	if len(intervals) == 0 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	start := 0
	for i := 1; i < len(intervals); i++ {
		fmt.Println(intervals[start][1] >= intervals[i][0])
		if intervals[start][1] < intervals[i][0] {
			if start != i {
				start++
				copy(intervals[start], intervals[i])
			}
			continue
		}
		if intervals[start][1] < intervals[i][1] {
			intervals[start][1] = intervals[i][1]
		}
	}
	return intervals[:start+1]
}
func main() {

	nums := [][]int{{1, 4}, {2, 3}} //{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
	fmt.Println(merge(nums))
}
