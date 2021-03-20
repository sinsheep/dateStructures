package main

import "fmt"

func waysToChange(n int) int {

	dp := make([]int, n+1)

	coins := []int{1, 5, 10, 25}

	for i := 0; i < 4; i++ {
		for j := 1; j <= n; j++ {
			if coins[i] < j {
				dp[j] += dp[j-coins[i]]
			}
			if coins[i] == j {
				dp[j]++
			}
			dp[j] %= 1000000007
		}
	}
	return dp[n]
}
func main() {

	fmt.Println(waysToChange(10))
}
