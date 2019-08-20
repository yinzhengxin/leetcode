#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1 2 3  -> # 1 # 2 # 3 #  m->2m+1  n->2n+1
        int m=nums1.size();
        int n=nums2.size();
        if(m>n){
            swap(m,n);
            swap(nums1,nums2);
        }
        // C1   leftMax1=nums1[(C1-1)/2] rightMin1=nums1[C1/2];
        // C2   leftMax2=nums2[(C2-1)/2] rightMin2=nums2[C2/2];
        int lo=0,hi=2*m,i,j,leftMax1,rightMin1,leftMax2,rightMin2;
        
        while(lo<=hi){
            i=(lo+hi)/2;
            j=m+n-i;
            leftMax1=(i==0)?INT_MIN:nums1[(i-1)/2];
            rightMin1=(i==2*m)?INT_MAX:nums1[i/2];
            
            leftMax2=(j==0)?INT_MIN:nums2[(j-1)/2];
            rightMin2=(j==2*n)?INT_MAX:nums2[j/2];
            
            if(leftMax1>rightMin2){
                hi=i-1;
            }else if(leftMax2>rightMin1){
                lo=i+1;
            }else{
                break;
            }
        }
        return (max(leftMax1,leftMax2)+min(rightMin1,rightMin2))/2.0; 
    }
};