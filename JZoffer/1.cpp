#include <stdio.h>
#include <iostream>
#include <vector>
using namespace  std;

//这个题 是一个左到右 上到下都是递增的数组。--->>>>>>>>从一行的最右的数开始比较。比它小则 列-1，比它大则行+1；
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m=array.size();
        int n=array[0].size();
        int i=0,j=n-1;
        while(i<m && j >=0 ){
            if(array[i][j]<target){
                i++;
            }else if(array[i][j]>target){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};