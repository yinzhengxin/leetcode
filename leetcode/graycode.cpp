#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<=0) return vector<int>{};
        if(n==1) return vector<int>{0,1};
        
        vector<int> res{0,1};
        int temp=1;
        for(int i=1;i<n;++i){
            temp*=2;
           /*  for(auto iter=res.rbegin(),endIter=res.rend();iter!=endIter;iter++){
               int interNum= *iter+temp;
               res.push_back(interNum);
            }
            */
           for(int j=res.size()-1;j>=0;j--){
                    int interNum= res[j]+temp;
                    res.push_back(interNum);
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> res=sol.grayCode(4);
    for(auto& num:res){
        cout<<num<<endl;
    }
    return 0;
}