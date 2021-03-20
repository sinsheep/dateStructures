package main

import "fmt"

func generateParenthesis(n int) []string {
	var par []string
	pair(n, n, "", &par)
	return par
}

func pair(pre, end int, sum string, par *[]string) {

	if pre == 0 && end == 0 {
		*par = append(*par, sum)
		return
	}
	if pre <= end {
		if pre >= 0 {
			pair(pre-1, end, sum+"(", par)
		}

		if pre < end {
			pair(pre, end-1, sum+")", par)
		}
	}
}

func main() {

	fmt.Println(generateParenthesis(3))
}
