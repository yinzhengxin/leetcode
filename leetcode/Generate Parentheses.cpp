#include <vector>
#include <string>
#include <iostream>
using namespace  std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(0,n,0,s,res,0);
        return res;
        
    }
    //参考答案更简单 1.不要i 用s.size()终止 2.dif 和num1变成 左右括号的数量
    //我这里 dif是指 ‘（’ 比 ‘）’多出来的数量 num1是指（ 的数量
    void dfs(int i,int n,int dif,string s, vector<string>& res,int num1){
        if(i==2*n-1 && num1==n)  {s=s+")";res.push_back(s);return;}
                    
        if(!dif){
            s=s+"(";
            dfs(i+1,n,1,s,res,num1+1);
        }else{
            if(num1<n){
                dfs(i+1,n,dif+1,s+"(",res,num1+1);
                dfs(i+1,n,dif-1,s+")",res,num1);
            }else{
                dfs(i+1,n,dif-1,s+")",res,num1);
            }
        }
        return ;
    }
};