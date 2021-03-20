package main

import (
	"fmt"
	"math"
)

func longestCommonPrefix(strs []string) string {
	str := ""
	m := len(strs)
	if m == 0 {
		return str
	}
	min := math.MaxInt32
	for i := 0; i < m; i++ {
		if len(strs[i]) < min {
			min = len(strs[i])
			// fmt.Println(min)
		}
	}
	for i := 0; i < min; i++ {
		for j := 0; j < m; j++ {
			if strs[j][i] != strs[0][i] {
				// fmt.Printf("%c %c", strs[j][i], strs[0][i])
				return str
			}
		}
		str += string(strs[0][i])
	}
	return str
}

func main() {

	strs := []string{"flower", "flow", "flight"}

	fmt.Println(longestCommonPrefix(strs))
}
