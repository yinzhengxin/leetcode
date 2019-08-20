#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        string res(len1+len2,'0');
        for(int i=len1-1;i>=0;i--){
                int num1_i=num1[i]-'0';
            for(int j=len2-1;j>=0;j--){
                int num2_j=num2[j]-'0';
                int temp=(res[i+j+1]-'0')+num1_i*num2_j;
                
                res[i+j+1]=temp%10+'0';
                res[i+j]=res[i+j]+temp/10;     
            }
        }
        
        for(int i=0;i<res.size();i++){
            if(res[i]!='0'||i==res.size()-1) {
                return res.substr(i,res.size()-i);
            }
        }
        return "";
    }
};