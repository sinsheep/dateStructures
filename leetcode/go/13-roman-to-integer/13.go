// Package main provides ss
package main

import "fmt"

func romanToInt(s string) int {
	num := 0
	value := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	num = value[s[len(s)-1]]
	for i := len(s) - 2; i >= 0; i-- {
		if value[s[i]] < value[s[i+1]] {
			num -= value[s[i]]
		} else {
			num += value[s[i]]
		}
	}
	return num
}

func main() {

	fmt.Println(romanToInt("IX"))
}
