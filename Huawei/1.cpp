#include <string>
#include <iostream>
using namespace std;
//getline func;
int main(){
    string s;
    getline(cin,s);
    int cnt=0;
    int i=s.size()-1;
    while(i>=0 && s[i]!=' '){
        i--;
        cnt++;
    }
    cout<<cnt; 
    return 0;
}