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
/*method 1
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* res=NULL;
        int count=0;
        inorder(pRoot,k,res,count);
        return res;
    }
    void inorder(TreeNode* pRoot, int k,TreeNode* &res,int &count){
        if(pRoot==NULL)    return;
        inorder(pRoot->left,k,res,count);
        count++;
        if(count==k)    res=pRoot;
        inorder(pRoot->right,k,res,count);
    }
};
*/
//method2
#include <stack>
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k<0||pRoot==NULL)    return NULL;
        stack< TreeNode*> s;
        int count=0;
        TreeNode*  p=pRoot;
        while(!s.empty()||p){
            /*
            TreeNode*  sTop=s.top();
            //这里出现了问题 循环导入了 ***不能这么写***
            while(sTop->left!=NULL){
                sTop=sTop->left;
                s.push(sTop);
            }
            */
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top();
            count++;
            if(count==k)    return p;
            s.pop();
            p=p->right;
        }
        return NULL;
    }
};