#include <iostream>
#include <vector>

using namespace  std;
//动态规划 
//1.自顶向下 是回溯的优化算法 用数组来存储
//2.自底向上
//3.贪心的做法。
class Solution {
public:
    bool canJump1(vector<int>& nums) {
        int len=nums.size();
        if(len==0 || len==1)    return true;
        vector<bool> dp(len,0);
        dp[0]=1;
        for(int i=1;i<len;++i){
            for(int j=i-1;j>=0;--j){
                if(dp[j]==true && nums[j]>=i-j ){
                    dp[i]=true;
                    break;
                }
            }      
        }
        return dp[len-1];     
    }
    //贪心的做法
    bool canJump2(vector<int>& nums) {
        int len=nums.size();
        int last=len-1;
        for(int i=len-2;i>=0;--i){
            if(nums[i]>=last-i){
                last=i;
            }
        }
        return last==0;
    }
};