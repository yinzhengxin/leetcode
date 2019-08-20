#include<string>
#include<iostream>
using namespace std;
//求最大回文 1.中心扩展
class Solution {
public:
    int palindromeLength(string s,int i,int j){
        int len=s.length();
        while(i>=0&&j<len&&s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;  
    }
    string longestPalindrome(string s) {
        if(s.empty()){
            return 0;
        }
        int start=0,end=0;
        int len1,len2,len;
        for(int i=0,s_len=s.length();i<s_len;i++){
            len1=palindromeLength(s,i,i);
            len2=palindromeLength(s,i,i+1);
            if(len1<len2){
                len=len2;
            }else{
                len=len1;
            }
            if(end-start+1<len){
                start=i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start,end-start+1);  
    }
};
int main(){
    Solution sol;
    cout<<sol.longestPalindrome("aba")<<endl;
    cout<<sol.palindromeLength("aba",0,0)<<endl;
    cout<<sol.palindromeLength("aba",0,1)<<endl;
    cout<<sol.palindromeLength("aba",1,1)<<endl;
    cout<<sol.palindromeLength("aba",1,2)<<endl;
    cout<<sol.palindromeLength("aba",2,2)<<endl;
    cout<<sol.palindromeLength("aba",2,3)<<endl;

}