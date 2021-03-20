package main

import "fmt"

func convert(s string, numRows int) string {
	var str string
	slen := len(s)
	nums := 0
	for i := 0; i < numRows; i++ {
		nums = 0
		for j := i; j < slen; j += (numRows-1-i)*2 - 1 {
			str += string(s[j])
			var space int
			if nums%2 == 1 && i != 0 && i != numRows-1 {
				space = ((slen-i)/2 - i + 1)
			} else {
				space = (slen/2 - i) + 1
			}
			for k := 0; k < space; k++ {
				str += " "
			}
			nums++
		}
		s += "\n"
	}
	return str
}

func main() {
	s := "LEETCODEISHIRING"
	n := 3
	fmt.Println(convert(s, n))
}
