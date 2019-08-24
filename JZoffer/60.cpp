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
        //BFS
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            queue<TreeNode*> q;
            if(pRoot==NULL) return res;
            q.push(pRoot);
            while(!q.empty()){
                int qsize=q.size();
                vector<int> vec;
                while(qsize--){
                    TreeNode* temp=q.front();
                    vec.push_back(temp->val);
                    q.pop();
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                res.push_back(vec);

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
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<endl;
        }
        cout<<"next"<<endl;
    }

    return 0;
}