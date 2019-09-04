#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int a[1001];
    memset(a,0,sizeof(a));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int temp;
        cin>>temp;
        a[temp]++;
    }
    cout<<"out"<<endl;
    for(int i=1;i<1001;i++){
        if(a[i]==1){
            cout<<i<<endl;
        }
    }
    return 0;
}