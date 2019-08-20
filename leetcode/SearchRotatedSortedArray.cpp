#include<vector>
#include<iostream>
using namespace std;
//假设没有重的元素。有重复元素的话 需要考虑重复元素

//递归调用！！！ 分而治之  二分法
class Solution {
public:
    int searchTarget(vector<int>& nums,int left,int right,int& target){
        if(right-left<2){
            if(target==nums[left])  {
                return left;
            }else if(target==nums[right]){
                return right;
            }else{
                return -1;
            }
        }     
        int mid=(left+right)>>1;
        if(nums[mid]==target) return mid;
        
        if((nums[mid]<nums[right]&&target<=nums[right]&&target>=nums[mid])||                              (nums[mid]>nums[right]&&target>=nums[left]&&target<=nums[mid])){
            int lhs=(nums[mid]<nums[right]?mid:left);
            int rhs=(nums[mid]<nums[right]?right:mid);     
            int temp;
            while(lhs<=rhs){
                temp=(lhs+rhs)>>1;
                if(nums[temp]==target) {
                    return temp;
                }else if(nums[temp]<target){
                    lhs=temp+1;
                }else{
                    rhs=temp-1;                    
                }
            }
            return -1;
        }else{
            left=nums[mid]<nums[right]?left:mid;
            right=nums[mid]<nums[right]?mid:right;
            return searchTarget(nums,left,right,target);
        }
    }   
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        return searchTarget(nums,0,nums.size()-1,target);
    }
};