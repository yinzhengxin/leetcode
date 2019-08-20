#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
/* 
    int reverse(int x) {
        int res=0;
        int sign=1;
        int remainder=0;
        if(x<0){
            sign=-1;
            x=-x;
        }
        while(x!=0){
            remainder=x%10;
            res=res*10+remainder;
            x/=10;
        }
        return sign*res;
    }
 */
//需要考虑栈溢出
    int reverse(int x) {
        int res=0;
        int remainder=0;
        while(x!=0){
            remainder=x%10;
            if(res>INT_MAX/10||(res==INT_MAX/10&&remainder>7)) return 0;
            if(res<INT_MIN/10||(res==INT_MIN/10&&remainder<-8)) return 0;
            res=res*10+remainder;
            x/=10;
        }
        return res;
    }  
};