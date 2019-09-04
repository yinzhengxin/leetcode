#include <algorithm>
#include <iostream>
#include <cmath>
using namespace  std;
//动态规划
class Solution {
public:
    int numSquares(int n) {  
        int dp[n+1];
        for(int i=0;i<=n;++i)   dp[i]=i;
        
        for(int i=1;i<=n;++i){
            int m=sqrt(i);
            if(m*m==i)   {dp[i]=1;continue;}
            int temp=INT_MAX;
            for(int j=1;j<=m;++j){
                temp=min(temp,dp[i-j*j]+1);
            }
            dp[i]=temp;
        }
        return dp[n]; 
    }
};