#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> a {1,2,3,4};
    vector<int> b;
    b=a;
    cout<<a[0]<<b[0]<<endl;
    b[0]=100;
    cout<<a[0]<<b[0]<<endl;
}