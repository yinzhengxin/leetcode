#include <vector>
#include <iostream>
using namespace  std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())    return 0;
        int len=nums.size();
        //cout<<len<<" ";
        int dp[len];
        for(int i=0;i<len;++i){
            dp[i]=1;
        }
        //cout<<dp[len-1]<<" ";
        for(int i=0;i<len;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]) {dp[i]=max(dp[i],dp[j]+1);}
    
            }
        //cout<<"i:"<<i<<" "<<dp[i]<<endl;
        }
        int res=INT_MIN;
        for(int i=0;i<len;++i){
            res=max(res,dp[i]);
        }
        return res;    
    }
};

int main(){
    Solution sol;
    vector<int> nums{1,2,3,4,2};
    cout <<sol.lengthOfLIS(nums);

}