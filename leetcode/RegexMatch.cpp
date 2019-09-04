#include <iostream>
#include <string>
using namespace  std;
//递归 或者 动态规划。
//递归 和剑指offer 52题一样。这里用动态规划，由底向上的方法来做。
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen=s.size();
        int pLen=p.size();
        bool dp[sLen+1][pLen+1];
        memset(dp,0,sizeof(dp));
        dp[sLen][pLen]=true;
        for(int i=sLen;i>=0;i--){
            for(int j=pLen-1;j>=0;j--){
                bool fM=(i<sLen) && (s[i]==p[j] || p[j]=='.'); 
                if(j+1<pLen && p[j+1]=='*'){
                    dp[i][j]=dp[i][j+2] || (fM && dp[i+1][j]);
                }else{
                    dp[i][j]=fM && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};