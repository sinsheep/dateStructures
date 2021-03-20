package main

func lengthOfLongestSubstring(s string) int {

	str := make(map[byte]int)
	n := len(s)

	rk, ans := -1, 0
	for i := 0; i < n; i++ {

		if i != 0 {
			delete(str, s[i-1])
		}

		for rk+1 < n && str[s[rk+1]] == 0 {
			str[s[rk+1]]++
			rk++
		}
		if ans < rk+1-i {
			ans = rk + 1 - i
		}
	}
	return ans
}

func main() {

}
