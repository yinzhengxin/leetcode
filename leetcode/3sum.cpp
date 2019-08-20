#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
         if(nums.empty() || nums.front()>0 || nums.back()<0)
            return {};
        
        int len=nums.size();
        vector<vector<int> > res;

        for(int i=0;i<len-2;i++){
            if(nums[i]>0) break;
            int temp=-nums[i];
            //nums[i]!=nums[i-1]
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                int lhs=i+1,rhs=len-1;
                while(lhs<rhs){
                    int sum=nums[lhs]+nums[rhs];
                    if(sum==temp){
                        res.push_back(vector<int>{nums[i],nums[lhs],nums[rhs]});
            //重复考虑        
                        while(lhs<rhs&&nums[lhs]==nums[lhs+1]) lhs++;
                        while(lhs<rhs&&nums[rhs]==nums[rhs-1]) rhs--;
                        lhs++;
                        rhs--;
                    }else if(sum>temp){
                        while(lhs<rhs&&nums[rhs]==nums[rhs-1]) rhs--;
                        rhs--;
                    }else{
                        while(lhs<rhs&&nums[lhs]==nums[lhs+1]) lhs++;
                        lhs++;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> num {-1,0,1,2,-1,-4};
    vector<vector<int> > res=sol.threeSum(num);
    return 0;
}