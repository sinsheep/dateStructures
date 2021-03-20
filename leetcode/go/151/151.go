package main

import (
	"fmt"
)

func reverseWords(s string) string {

	flag := 1
	var list, tmp string
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ' ' && flag == 0 {
			flag = 1
			for j := len(tmp) - 1; j >= 0; j-- {
				list += string(tmp[j])
			}
			tmp = ""
		} else if s[i] != ' ' {
			tmp += string(s[i])
			if len(list) != 0 && flag == 1 {

				list += " "

			}
			flag = 0
			// fmt.Println(s[i], i, tmp)
		}
	}
	if len(tmp) != 0 && flag == 0 {

		for j := len(tmp) - 1; j >= 0; j-- {
			list += string(tmp[j])
		}
	}
	return list
}

func main() {

	var s string
	s = "  hello world!  "
	fmt.Println(reverseWords(s))

}
