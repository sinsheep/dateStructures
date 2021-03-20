package main

// var dir = [][]int{
// 	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
// }
// func dfs(dx,dy,orient int) {

// 	if
// }
func generateMatrix(n int) [][]int {
	nums := make([][]int, n)
	for i := 0; i < n; i++ {
		nums[i] = make([]int, n)
	}

	taget := n * n
	num := 1
	l, d, r, u := 0, 0, n-1, n-1

	for num <= taget {

		for i := l; i <= r; i++ {
			nums[u][i] = num
			num++
		}
		d++
		for i := d; i <= u; i++ {
			nums[u][i] = num
			num++
		}
		d++
	}
	return nums
}
func main() {

}
