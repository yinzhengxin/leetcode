#include <vector>
#include <iostream>

using namespace std;
//dfs 回溯法 在matrix中需要路径 str
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<int> visit(rows*cols,0);
        bool res;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res=dfs(matrix,rows,cols,str,i,j,visit);
                if(res)    return true;
            }
        }
        return false;
    }
    
    bool dfs(char* matrix, int rows, int cols, char* str,int i,int j,vector<int>& visit){
        if( i<0 || i>=rows || j<0 || j>=cols)    return false;
        if(matrix[i*cols+j]==*str && visit[i*cols+j]==0 ){
            
            visit[i*cols+j]=1;
            if(*(str+1)=='\0'){
                visit[i*cols+j]=0;
                return true;
            }
            
            bool bo=false;
            bo=bo || dfs(matrix,rows,cols,str+1,i+1,j,visit)||
            dfs(matrix,rows,cols,str+1,i-1,j,visit)||
            dfs(matrix,rows,cols,str+1,i,j+1,visit)||
            dfs(matrix,rows,cols,str+1,i,j-1,visit);
            //这里注意 回溯返回之前要 把改变的值改回来。 最后vistit为0
            //也加加上判读 if(!bo){visit[]=0;}这样只有true的路径 visit值为1.
            visit[i*cols+j]=0;
            return bo;
             
        }else{
                return false;
        }
    }
};
int main(){
    Solution sol;
    char matrix[20]="qwerasdfzxcv";
    char str1[20]="qwsderf";    //1
    char str2[20]="qwerfdsaq";  //重复 0
    char str3[20]="qazxswedc";  // 1
    char str4[20]="adfrew";     // 0
    cout<<sol.hasPath(matrix,3,4,str1)<<endl;   
    cout<<sol.hasPath(matrix,3,4,str2)<<endl;  
    cout<<sol.hasPath(matrix,3,4,str3)<<endl;  
    cout<<sol.hasPath(matrix,3,4,str4)<<endl;  
    return 0;
}