#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void spiralOrder(vector<vector<int> >& matrix,int row,int col,vector<int>& res) {
        if(row<=0||col<=0)  return;
        int i=(matrix.size()-row)/2;
        int j=(matrix[0].size()-col)/2;
        for(int m=j;m<matrix[0].size()-j;m++)   res.push_back(matrix[i][m]);
        for(int n=i+1;n<matrix.size()-i;n++)    res.push_back(matrix[n][matrix[0].size()-j-1]);
        if(row!=1){
            for(int p=matrix[0].size()-j-2;p>j;p--) res.push_back(matrix[matrix.size()-i-1][p]);
        }
        if(col!=1){
            for(int q=matrix.size()-i-1;q>i;q--)    res.push_back(matrix[q][j]);
        }
        spiralOrder(matrix,row-2,col-2,res);
    }

    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        if(matrix.empty())  return vector<int>{};
        vector<int> res;
        spiralOrder(matrix,matrix.size(),matrix[0].size(),res);
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int> >matrix{{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
    vector<int> res;
    res=sol.spiralOrder(matrix);
    for(auto & num:res){
        cout<<num<<endl;
    }

    return 0;
}