#include <stdio.h>
#include <iostream>
#include <vector>
using namespace  std;
// 已知前序和中序  还原出树。
// 用递归来解决
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int vinSize=vin.size();
        if(!vinSize)    return NULL;
        int mid=0;
        TreeNode* root=new TreeNode(pre[0]);

        vector<int> left_pre,left_vin,right_pre,right_vin;
        while(vin[mid]!=pre[0]){
            mid++;
        }
        for(int i=0; i<mid; ++i){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }

        for(int i=mid+1;i<vinSize;++i){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        root->left=reConstructBinaryTree(left_pre,left_vin);
        root->right=reConstructBinaryTree(right_pre,right_vin);
        return root;

    }
};