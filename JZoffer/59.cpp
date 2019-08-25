#include <stdio.h>
#include <vector>
#include <queue>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        deque<TreeNode*> q;
        vector<vector<int> > res;
        if(!pRoot)   return res;
        q.push_back(pRoot);
        int direction=1;
        while(!q.empty()){
            int qSize=q.size();
            vector<int> curVec;
            while(qSize--){
                if(direction==1){
                    TreeNode* curNode=q.front();
                    q.pop_front();
                    curVec.push_back(curNode->val);
                    if(curNode->left)   q.push_back(curNode->left);
                    if(curNode->right) q.push_back(curNode->right);
                }else{
                    TreeNode* curNode=q.back();
                    q.pop_back();
                    curVec.push_back(curNode->val);
                    if(curNode->right) q.push_front(curNode->right);
                    if(curNode->left)   q.push_front(curNode->left);
                
                }
            }
            res.push_back(curVec);
            direction=-direction;
        }

        return res;
    }
    
};

int main(){
    Solution sol; 
    TreeNode* pRoot=new TreeNode(0);
    pRoot->left=new TreeNode(1);
    pRoot->right=new TreeNode(2);
    pRoot->right->right=new TreeNode(3);
    vector<vector<int> > res=sol.Print(pRoot);
    cout<<"out:\n";
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<endl;
        }
        cout<<"next"<<endl;
    }

    return 0;
}