package main

import "fmt"

func intToRoman(num int) string {
	sum := ""
	value := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	key := []string{
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
	}
	for i := 0; i < 13; i++ {
		for num >= value[i] {
			sum += key[i]
			num -= value[i]
		}
	}

	return sum

}
func main() {

	fmt.Println(intToRoman(123))
}
