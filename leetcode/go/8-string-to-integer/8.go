package main

import (
	"fmt"
	"math"
	"strings"
)

func myAtoi(str string) int {
	var num int
	var flag int
	str = strings.TrimSpace(str)
	if len(str) == 0 {
		return num
	}
	if str[0] == '-' {
		flag = 1

	} else if str[0] == '+' {
		flag = 0
	} else if str[0] > '9' || str[0] < '0' {
		return num
	} else {
		num = int(str[0] - '0')
	}
	for i := 1; i < len(str); i++ {
		if str[i] > '9' || str[i] < '0' {
			break
		}
		num = num*10 + int(str[i]-'0')
		// fmt.Println(num)

		if flag == 1 {
			num = -num
			flag = 0
		}
		if num > math.MaxInt32 {
			return math.MaxInt32 - 1
		}
		if num < math.MinInt32 {
			return math.MinInt32
		}
	}
	return num
}

func main() {
	numStr := "-91283472332"

	fmt.Println(myAtoi(numStr))
}
