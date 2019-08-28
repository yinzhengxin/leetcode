#include <stdio.h>
#include <iostream>
using namespace  std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* res=NULL;
        if(pNode->right){
            res=pNode->right;
            while(res->left)    res=res->left;
        }else if(pNode->next){
            TreeLinkNode* child=pNode;
            TreeLinkNode* parent=pNode->next;
            while(parent!=NULL && parent->right==child){
                child=parent;
                parent=child->next;
            }
            res=parent;
        }
        return res;

    }
};