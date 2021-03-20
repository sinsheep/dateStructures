package main

import "fmt"

func isHappy(n int) bool {

	var num map[int]int
	num = make(map[int]int)
	num[n] = 1
	for n != 1 {
		if num[n] > 1 {
			return false
		}
		tmp := 0
		for n != 0 {
			tmp += (n % 10) * (n % 10)
			n /= 10
		}
		n = tmp
		_, ok := num[n]
		if ok != false {
			return false
		} else {
			num[n] = 1
		}
	}
	return true
}

func main() {

	fmt.Println(isHappy(19))
}
