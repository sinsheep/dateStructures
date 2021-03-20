package main

import "fmt"

func dfs(grid *[][]byte, dx, dy int) {

	if dx < 0 || dy < 0 || dx >= m || dy >= n {
		return
	}
	if (*grid)[dx][dy] == '0' {
		return
	}
	(*grid)[dx][dy] = '0'

	for k := 0; k < 4; k++ {
		dfs(grid, dx+pos[k][0], dy+pos[k][1])
	}
}

var m, n int
var pos = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

func numIslands(grid [][]byte) int {
	var sum int
	m = len(grid)
	if m == 0 {
		return sum
	}
	n = len(grid[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' {
				dfs(&grid, i, j)
				sum++
			}
		}
	}
	return sum
}
func main() {
	island := [][]byte{
		{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'},
	}
	fmt.Println(numIslands(island))
}
