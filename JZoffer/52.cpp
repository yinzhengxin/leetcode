#include <iostream>
#include <string>
using namespace  std;
//递归当方法来做
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(*str=='\0' && *pattern== '\0'){
            return true;
        }

        //当str为\0 pattern可以不为\0 可以为 *
        if(*str != '\0' && *pattern == '\0'){
            return false;
        }
        if(*(pattern+1)=='*'){
            if(*pattern == *str || (*pattern=='.' && *str!='\0')){
                return match(str+1,pattern+2) || match(str+1,pattern) || match(str,pattern+2);
            }else{
                return match(str,pattern+2);
            }        
        }else if(*str == *pattern || (*str!='\0' && *pattern == '.') ){
                return match(str+1,pattern+1);
        }else{
            return false;
        }
    
    }
};
int main(){
    Solution sol;
    char a[10]="";
    char b[10]="a*b*";
    cout<<sol.match(a,b);
}