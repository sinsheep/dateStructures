package main

import "fmt"

var flag, m, n int
var dx = []int{1, 0, -1, 0}
var dy = []int{0, 1, 0, -1}

func dfs(board [][]byte, tx, ty int, word string) {
	if len(word) == 0 {
		flag = 1
		return
	}
	if flag == 1 || tx < 0 || ty < 0 || tx >= m || ty >= n {
		return
	}
	if board[tx][ty] != word[0] {
		return
	}
	tmp := board[tx][ty]
	board[tx][ty] = '.'
	for i := 0; i < 4; i++ {
		dfs(board, tx+dx[i], ty+dy[i], word[1:])
		fmt.Printf("%c", tmp)
	}
	board[tx][ty] = tmp
}
func exist(board [][]byte, word string) bool {
	m = len(board)
	if m == 0 {
		return false
	}
	n = len(board[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == word[0] {
				dfs(board, i, j, word)
			}
			if flag == 1 {
				return true
			}
		}
	}
	return false
}

func main() {
	board := [][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}
	fmt.Println(exist(board, "ABCB"))
}
