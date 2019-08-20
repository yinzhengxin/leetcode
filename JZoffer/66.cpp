#include <vector>
#include <iostream>
using namespace  std;
int x[4]={0,0,-1,1};
int y[4]={-1,1,0,0};
//x y 设置为全局变量。
//使用的dfs 深度搜索来解决问题
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0)    return 0;
        vector<int> visit(rows*cols,0);
        int res=1;
        dfs(threshold,rows,cols,0,0,visit,res);
        return res;
    }
    
private:
    void dfs(int threshold, int rows, int cols,int m, int n,vector<int>& visit,int &res ){
        visit[m*cols+n]=1;
        for(int i=0;i<4;i++){
            int r=m+x[i];
            int c=n+y[i];
            if((r>=0) && (r<rows) && (c>=0) && (c< cols) && (visit[r*cols+c]==0) && (sumNum(r,c)<=threshold) ){
                res++;
                dfs(threshold,rows,cols,r,c,visit,res);
            }
        }
    }
    
    int sumNum(int x,int y){
        int res=0;
        while(x){
            res=res+x%10;
            x/=10;
        }
        while(y){
            res=res+y%10;
            y/=10;
        }
        return res;
    }
};

int main(){
    Solution sol; 
    cout<<sol.movingCount(1,10,10)<<endl;
    cout<<sol.movingCount(2,10,10)<<endl;
    cout<<sol.movingCount(10,10,10)<<endl;
    return 0;
}