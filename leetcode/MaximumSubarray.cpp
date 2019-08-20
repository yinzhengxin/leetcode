#include <vector>
#include <iostream>

using namespace  std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum=INT_MIN;
        int temp=0;
        for(const auto& num:nums){
            if(temp+num>maxNum) {maxNum=temp+num;}
            temp=temp+num;
            if(temp<0)  {temp=0;}
        }
        return maxNum;
    }
};