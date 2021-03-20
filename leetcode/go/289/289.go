package main

import (
	"fmt"
)

func gameOfLife(board [][]int) {
	dx := []int{1, -1, 0, 0, 1, -1, 1, -1}
	dy := []int{1, -1, 1, -1, -1, 1, 0, 0}
	m := len(board)
	n := len(board[0])
	var tmp = make([][]int, m, m)
	for i := 0; i < m; i++ {
		tmp[i] = make([]int, n, n)
		for j := 0; j < n; j++ {
			sum := 0
			for k := 0; k < 8; k++ {
				tx := i + dx[k]
				ty := j + dy[k]
				if tx < 0 || tx >= m || ty < 0 || ty >= n {
					continue
				}
				if board[tx][ty] == 1 {
					sum++
				}
			}
			if board[i][j] == 0 && sum == 3 {
				tmp[i][j] = 1
				continue
			}
			if board[i][j] == 1 {
				if sum < 2 || sum > 3 {
					tmp[i][j] = 0
					continue
				}
			}
			tmp[i][j] = board[i][j]
		}
	}
	copy(board, tmp)
	fmt.Println(board)
}

func main() {

	game := [][]int{
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0},
	}
	gameOfLife(game)
}
