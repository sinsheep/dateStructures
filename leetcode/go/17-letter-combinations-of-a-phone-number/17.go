package main

import "fmt"

var dic = []string{
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
}

func dfs(nums *[]string, num, tmp string) {
	if len(num) == 0 {
		*nums = append(*nums, tmp)
		return
	}
	l := num[0] - '0'
	for i := 0; i < len(dic[l]); i++ {
		dfs(nums, num[1:], tmp+string(dic[l][i]))
	}
}

func letterCombinations(digits string) []string {
	var nums []string
	if len(digits) != 0 {
		dfs(&nums, digits, "")
	}
	return nums
}

func main() {

	fmt.Println(letterCombinations("23"))
}
