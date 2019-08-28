#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int res=0;
        int len=str.length();
        int sign=1;
        int cur=0;
        if(str[0]=='-'){
            sign=-1;
            cur=1;
        }else if(str[0]=='+'){
            cur=1;
        }
        while(cur!=len){
            if(str[cur]<'0'||str[cur]>'9')    return 0;
            res=res*10+str[cur]-'0';
            cur++;
        }
        return sign*res;
    }
};