#include <string>
#include <iostream>
#include <vector>
using namespace  std;
//情况考虑要充分。dp 
//1。 if s[i]为0 时，       s[i-1]为  0 1-2 3-9 三种情况
//2。 if s[i]不为0时，      s[i-1]为0    s[i-1]不为0（求相邻两个数与26比较） 两种情况
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')  return 0;
        int len=s.size();
        vector<int> dp(len,1);
        for(int i=1;i<len;++i){
            if(s[i]=='0'){
                if( ((s[i-1]-'0')>2) || s[i-1]=='0'){
                    return 0;
                }else{
                    if(i==1){
                        dp[1]=1;
                    }else{
                        dp[i]=dp[i-2];
                    }
                }
            }else{
                int num=10*(s[i-1]-'0')+s[i]-'0';
                if(s[i-1]=='0' || num>26){
                    dp[i]=dp[i-1];
                }else{
                    if(i==1){
                        dp[1]=2;
                    }else{
                         dp[i]=dp[i-1]+dp[i-2];
                    }
                }      
            }
        }
        return dp[len-1];      
    }
};
int main(){
    Solution sol;
    string s="110";
    cout<<sol.numDecodings(s);
}