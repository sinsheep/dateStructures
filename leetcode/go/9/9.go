package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var s string = strconv.Itoa(x)
	slen := len(s)
	for i := 0; i < slen/2; i++ {
		if s[i] != s[slen-i-1] {
			return false
		}
	}
	return true

}
func main() {
	var num int
	fmt.Scanln(&num)
	fmt.Println(isPalindrome(num))

}
