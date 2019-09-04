#include <string>
#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    char c;
    int cnt=0;
    cin>>c;
    for(int i=0;i<s.size();++i){
        if(s[i]==c || (c<='z' && c>='a' && s[i]==c-32) 
           || (c<='Z' && c>='A' && s[i]==c+32)){
           cnt++;
        }
    }
    cout<<cnt;
    return 0;
}