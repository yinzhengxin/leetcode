//kmp算法 next[i]的值为 模式串[0,i]的最长前缀的下标。 前缀不包括自己。（前缀和后缀匹配）

#include <iostream>
#include <vector>
#include <string>
using namespace  std;

void getNext(string str,vector<int> &next){
    next[0]=-1;
    int k=-1;
    int len=next.size();
    for(int i=1;i<len;++i){
        while(k>=0 && str[k+1]!=str[i] ){
            k=next[k];
        }
        if(str[k+1]==str[i]){
            k++;
        }
        next[i]=k;
    }
}

int match(string str1,string str2){ //str1 > str2
    if(str1.size()<str2.size()) return -1;
    if(str2.size()==0 || str1==str2 )  return 0;

    vector<int> next;
    next.resize(str2.size());
    getNext(str2,next);
    int j=0;
    for(int i=0;i<str1.size();++i){
        while(j>0 && str1[i]!=str2[j]){
            j=next[j-1]+1;
        }

        if(str1[i]==str2[j]){
            j++;
        }

        if(j==str2.size()){
            return i-j+1;
        }
    }
    return -1;
}

void textGetNext(){
    vector<int>  next;
    string str="ababcdab"; //-1 -1 0 1 -1 -1 0 1
    next.resize(str.size());
    getNext(str,next);
    for(const auto & num:next){
        cout<<num<<' ';
    }
    return ;
}
