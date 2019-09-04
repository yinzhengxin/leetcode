#include <stdio.h>
#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len=0;
        int blank=0;
        while(str[len]!='\0'){
            if(str[len]==' '){
                blank++;
            }
            len++;
        }
        int totalLen=len+2*blank;
        int cur=totalLen;
        while(cur!=len){
            if(str[len]==' '){
                str[cur--]='0';
                str[cur--]='2';
                str[cur]='%';
            }else{
                str[cur]=str[len];
            }
            cur--;
            len--;
        }
        return ;
	}
};