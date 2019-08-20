#include<string>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//求最大回文 2.动态规划
class Solution{
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        vector< vector<bool> > dp(n,vector<bool>(n));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j||(s[i]==s[j]&&(i+1==j||dp[i+1][j-1]==true))){
                    dp[i][j]=true;
                    if(j-i+1>res.size()){
                        res=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.longestPalindrome("abbazxc")<<endl;
}