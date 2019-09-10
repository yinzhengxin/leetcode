#include <iostream>
#include <vector>
using namespace  std;
//dp 动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        int dp[amount+1];
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=amount;++i){
            for(auto & coin:coins){
                if(i-coin<0 || (i-coin>0 && dp[i-coin]==-1))    {continue;}
                if(i==coin)     {dp[i]=1;break;}
                if(i-coin>0  && dp[i-coin]>0){
                    if(dp[i]==-1){dp[i]=dp[i-coin]+1;}
                    else{dp[i]=min(dp[i],dp[i-coin]+1);}
                }
            }
        }
        return dp[amount];
    }
};