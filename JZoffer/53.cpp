#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL)    return false;
        if(*string=='+' || *string=='-'){
            string++;
        }
        if(*string == '\0')    return false;
        int num=0,dot=0,nume=0;
        while(*string!='\0'){
            if(*string>='0' && *string<='9' ){
                string++;
                num=1;
            }else if(*string == '.'){
                if(dot>0 || nume>0){
                    return false;
                }
                string++;
                dot=1;
            }else if(*string=='e' || *string=='E'){
                if(num==0 || nume>0)    {return false;}
                string++;
                nume=1;
                if(*string == '+' || *string == '-'){
                    string++;
                }
                if(*string == '\0'){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};