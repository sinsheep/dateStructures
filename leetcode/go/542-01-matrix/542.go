package main

import (
	"fmt"
)

type point struct {
	x, y int
}

func updateMatrix(matrix [][]int) [][]int {
	m, n, nums := len(matrix), len(matrix[0]), 0

	var p []point
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				p = append(p, point{i, j})
				nums++
			} else {
				matrix[i][j] = m * n
			}
		}
	}
	start := 0
	for {
		if nums <= start {
			break
		}
		dx := []int{1, 0, -1, 0}
		dy := []int{0, 1, 0, -1}
		for i := 0; i < 4; i++ {
			tx := p[start].x + dx[i]
			ty := p[start].y + dy[i]
			if tx < 0 || ty < 0 || tx >= m || ty >= n {
				continue
			}
			if matrix[tx][ty] > matrix[p[start].x][p[start].y]+1 {
				matrix[tx][ty] = matrix[p[start].x][p[start].y] + 1
				p = append(p, point{tx, ty})
				nums++
			}
		}
		start++
	}
	return matrix
}
func main() {

	nums := [][]int{
		{0, 0, 0},
		{0, 1, 0},
		{1, 1, 1},
	}
	fmt.Println(updateMatrix(nums))
}
