package main

import (
	"fmt"
)

func P5660() {
	var s string
	fmt.Scanf("%s", &s)
	if len(s) != 8 {
		return
	}
	num := 0
	for idx := range s {
		if s[idx] == '1' {
			num++
		}
	}
	fmt.Println(num)
}

// func main() {
// 	P5660()
// }
