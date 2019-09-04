#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.empty())    return vector<int>{};
        vector<int> l2r;
        vector<int> r2l;
        int len=A.size();
        for(int i=0;i<len;i++){
            if(l2r.empty()){ 
                l2r.push_back(A[i]);
            }else{
                l2r.push_back(l2r.back()*A[i]);
            }
            if(r2l.empty()){    
                r2l.push_back(A[len-1-i]);
            }else{
                r2l.push_back(r2l.back()*A[len-1-i]);
            }
        }
        vector<int> res;
        for(int i=0;i<len;++i){
            if(!i) {res.push_back(r2l[len-2]);continue;}
            if(i==len-1){res.push_back(l2r[len-2]);continue;}
            res.push_back(l2r[i-1]*r2l[len-1-i-1]);
        }
        return res;
    }
};