#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int N=3005;
int dp[N][N];
int a[N];

int score(int max){
    for(int i=1; i<=max; i++){
        for(int m=1,n=i;n<=max;++m,++n){ 
            int t1=std::max(dp[m+1][n]+a[m],dp[m][n-1]+a[n]);
            int t2=std::min(dp[m+1][n],dp[m][n-1]);
            if(max%2==0){
                dp[m][n]=(m+n)%2?t1:t2;
            }else{
                dp[m][n]=(m+n)%2?t2:t1;
            }
        }
    }
    return dp[1][max];
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){cin>>a[i];}
    cout<<score(n);
    return 0;
}
