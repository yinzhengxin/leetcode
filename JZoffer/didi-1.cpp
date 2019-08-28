#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000];
char b[100000];
int num;
void swapNum(int &x,int &y,int i){
    if(i<1)	return;
    if(i==1 && (b[0]=='+' || b[0]=='*')&& x>y){
        int temp=x;
        x=y;
        y=temp;
    }
   // +a+b+  +a+b-
   // -a-b+  -a-b-
   // *a*b 
   // /a/b 
   // +a*b  -a*b

    if(b[i-1]==b[i-2] && b[i-1]!='/' && x>y && (i==num-1 || (b[i]!='*' && b[i]!='/')) ){
        int temp=x;
        x=y;
        y=temp;
    }else if(b[i-1]=='*'&& b[i-1]!='/' && x>y){
        int temp=x;
        x=y;
        y=temp;
    }
}

int main(){
    cin>>num;
    for(int i=0;i<num-1;i++){
        cin>>a[i];       
        cin>>b[i];
    }
    cin>>a[num-1];
   
    for(int i=0;i<num-1;i++){
   		for(int j=num-1;j>=i+1;j--){
        
         //   cout<<j<<'j'<<endl;
        	swapNum(a[j-1],a[j],j);
    	}
    }
    for(int m=0;m<num-1 ; m++){
        cout<<a[m]<<' '<<b[m]<<' ';
    }
    cout<<a[num-1];
    return 0;
}