#include<vector>
#include<iostream>
using namespace std;
class Solution;
class Solution {
public:
    int maxArea(vector<int>&& height) {
        int i=0,j=height.size()-1;
        int maxArea= 0;
        int temp=0;
        while(i<j){
            temp=(height[i]<height[j]?height[i]:height[j])*(j-i);
            if(maxArea<temp){
                maxArea=temp;
            }
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
  
        } 
        return maxArea;
    }
};



int main(){
    Solution sol;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout<<sol.maxArea({1,8,6,2,5,4,8,3,7});
    return 0;
}