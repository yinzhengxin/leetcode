#include <iostream>
#include <vector>
#include <string>

using namespace  std;

class Solution {

public:
    vector<string> letterCombinations(string digits) {
        vector< vector<char> > phone{{'a','b','c'},{'d','e','f'},{'g','h','i'}, {'j','k','l'},{'m','n','o'},{'p','q','r','s'},                                   {'t','u','v'},{'w','x','y','z'}};
        if(digits.empty())  return vector<string>{};
        
        vector<string> resNext=letterCombinations(digits.substr(1));
        
        int curNum=digits[0]-'0'-2;
        vector<char> vc(phone[curNum]);
        vector<string> resCur;
        
        for(auto &each:vc){
            vector<string> temp(resNext);
            //这一行不能丢，temp为空的时候 char->string
            //1. char* ->string string s(地址,n) or string s(地址)； 
            //2. char -> string string s(n个char,char)
            //3. string ->char* strcpy(地址，str.c_str());
            //将string转char*，可以使用string提供的c_str()或者data()函数。
            //其中c_str()函数返回一个以'\0'结尾的字符数组，而data()仅返回字符串内容，而不含有结束符'\0'。
            //并且c_str()返回是临时指针不能进行操作。并且其指向的是原string数据，改变其指针指向的值，string会发生改变。
            
            if(temp.empty()){string s(&each,1);resCur.push_back(s);continue;}
            for(auto& str:temp){
                str=each+str;
            }
            resCur.insert(resCur.end(),temp.begin(),temp.end());
        }
        return resCur;        
    }
};

int main(){
    Solution sol;
    string digits="23";
    vector<string> res=sol.letterCombinations(digits);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<endl;
    }
}