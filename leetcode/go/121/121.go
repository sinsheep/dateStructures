package main

import "fmt"

func maxProfit(prices []int) int {

	maxNum, initNum := 0, prices[0]

	for i := 1; i < len(prices); i++ {
		if initNum >= prices[i] {
			initNum = prices[i]
		} else {

			if maxNum == 0 {
				maxNum = prices[i] - initNum
			} else if maxNum < prices[i]-initNum {
				maxNum = prices[i] - initNum
			}
		}
	}
	return maxNum
}

func main() {
	var stock []int = []int{7, 1, 5, 3, 6, 4}
	fmt.Println(maxProfit(stock))

}
