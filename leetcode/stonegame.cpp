#include <vector>
#include <iostream>
#include <stdio.h>
using namespace  std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N=piles.size();
        int dp[N+2][N+2];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=N;++i){
            for(int m=1,n=i;n<=N;++m,++n){
                if((n-m+1)%2==0){
                    dp[m][n]=max(piles[m-1]+dp[m+1][n],piles[n-1]+dp[m][n-1]);
                }else{
                    dp[m][n]=min(-piles[m-1]+dp[m+1][n],-piles[n-1]+dp[m][n-1]);
                }
            }
        }
        return dp[1][N]>0; 
    }
};