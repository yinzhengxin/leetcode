#include <stdio.h>
#include <iostream>
using namespace  std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL) return true;
        return Symmetrical( pRoot->left, pRoot->right);
        
    }

private:
    bool Symmetrical(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)   return true;
        if( (left&&!right) || (!left&&right) || left->val!=right->val )   return false;
        return  Symmetrical(left->left,right->right) && Symmetrical(left->right,right->left);
    }
};