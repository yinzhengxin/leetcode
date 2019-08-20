#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(m.find(target-nums[i])!=m.end()){
                return vector<int>{m[target-nums[i]],i};
            }else{
                m.insert(make_pair(nums[i],i));
            }
        }
        return vector<int>{-1,-1};
    }
};