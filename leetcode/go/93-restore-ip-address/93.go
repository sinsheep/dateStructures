package main

import (
	"fmt"
	"strconv"
)

var ipPool []string

func dfs(num, step int, ip, tmp string) {
	if num > 255 {
		return
	}
	if step > 4 {
		return
	}
	if len(ip) == 0 && step == 4 {
		ipPool = append(ipPool, tmp)
	}
	dfs(num*10+int(ip[0]-'0'), step, ip[1:], tmp)
	dfs(0, step+1, ip, tmp+strconv.Itoa(num)+".")
	fmt.Println(tmp)
}

func restoreIpAddresses(s string) []string {
	dfs(0, 0, s, "")
	return ipPool
}
func main() {

	fmt.Println(restoreIpAddresses("25525511135"))
}
