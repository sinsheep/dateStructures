package main

import "fmt"

func rotate(matrix [][]int) {

	n := len(matrix)
	for i := 0; i < n/2; i++ {
		for j := i; j < n-1-i; j++ {
			matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-1-j][i] = matrix[n-1-j][i], matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1]

			fmt.Println(i, j)
		}
	}

	fmt.Println(matrix)
}

func main() {
	matrix := [][]int{
		{5, 1, 9, 11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15, 14, 12, 16},
	}
	rotate(matrix)
}
