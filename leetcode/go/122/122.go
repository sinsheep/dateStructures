package main

import "fmt"

func maxProfit(prices []int) int {
	var maxSum, minNum, Sum int
	minNum = prices[0]
	for i := 1; i < len(prices); i++ {
		if minNum >= prices[i] || prices[i] < prices[i-1] {
			minNum = prices[i]
			Sum += maxSum
			maxSum = 0
		} else if maxSum < prices[i]-minNum {
			maxSum = prices[i] - minNum
		}
	}
	if maxSum != 0 {
		Sum += maxSum
	}
	return Sum
}

func main() {

	nums := []int{7, 6, 4, 3, 1}

	fmt.Println(maxProfit(nums))
}
