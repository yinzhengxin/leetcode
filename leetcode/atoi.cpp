#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        int sign=0,res=0;
        int i=0;
        while(i<len&&str[i]==' ') i++;
        if(i==len) return 0;
        if(str[i]=='-'){ 
            sign=-1;
        }else if(str[i]=='+'){
            sign=1;
        }else if(str[i]>='0'&&str[i]<='9'){
            res=str[i]-'0';
        }else{
            return 0;
        }
        int temp=0;
        while(++i<len&&str[i]>='0'&&str[i]<='9'){
            temp=(str[i]-'0')*sign;
            if(res>INT32_MAX/10||(res==INT32_MAX/10&&temp>7)) return INT32_MAX;
            if(res<INT32_MAX/10||(res==INT32_MIN/10&&temp<-8)) return INT32_MIN;
            res=res*10+temp;
        }
        return res;
    }
};