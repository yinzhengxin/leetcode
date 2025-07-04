package main

import "fmt"

// getOneDayMaxProfile dp[m] = max(dp[m], dp[m-vi]+wi)  if m>vi
func getOneDayMaxProfile(m, n int, v, w []int) int {
	dp := make([]int, 0, m+1)
	for i := 0; i < n; i++ {
		for j := 1; j <= m; j++ {
			if j > w[i] {
				dp[j] = max(dp[j], dp[j-v[i]+w[i]])
			}
		}
	}
	return dp[m]
}

func main() {
	var T, N, M int 
	fmt.Scanf("%d %d %d\n", &T,&N,&M)

	

}
