#include <vector>
#include <iostream>
#include <deque>
using namespace std;
//滑动窗口的最大值。
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(num.empty() || size==1)    return num;

        deque<int> q;
        int numSize=num.size();
        vector<int> res;
        q.push_back(0);
        for(int i=1;i<numSize;i++){
            if(i-q.front()>=size){
                q.pop_front();
            }
            //注意这里需要判断 q是否为 空
            while(!q.empty()&&num[i]>=num[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            //不是一开始就保存值
            if(i>=size-1){
                res.push_back(num[q.front()]);
            }
        }
        return res;
    }
};

void printVector(vector<int>& nums){
    for(const auto &num:nums){
        std::cout<<num<<"  ";
    }
    std:cout<<"vector print"<<endl;
}
int main(){
    Solution sol;
    char matrix[20]="qwerasdfzxcv";
    vector<int> t1{1,8,6,2,5,4,8,3,7};
    vector<int> t2{3,1,3,4,5,6,7,8,1};
    vector<int> t3{1,2,3,4,5,6,7,8,9};
    vector<int> res;
    res=sol.maxInWindows(t1,3);
    printVector(res);
    res=sol.maxInWindows(t2,3);
    printVector(res);
    res=sol.maxInWindows(t3,3);
    printVector(res);
    return 0;
}
