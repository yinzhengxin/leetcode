#include<vector>
using namespace std;
//回溯 深度优先算法
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;       
        dfs(nums,res,0);  
        return res;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& res,int i){
        if(i==nums.size()-1)  return res.push_back(nums); 
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            dfs(nums,res,i+1);
            swap(nums[i],nums[j]);
        }  
    }
};