#include <stdio.h>
#include <string>

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
    char* Serialize(TreeNode *root) {    
        if(root==NULL)    return  "#";
        string temp=to_string(root->val);
        temp+='!';
        char *left=Serialize(root->left);
        char *right=Serialize(root->right);
        char *res=new char[strlen(left)+strlen(right)+temp.size()];
        //首先注意这里是 strcpy strlen strcat c类型字符串函数的使用，这里的参数都是char * 类型！！！！！
        strcpy(res,temp.c_str());
        strcat(res,left);
        strcat(res,right);
        return res;
    }
    TreeNode* Deserialize(char *str) {
        //这里为了保证dfs中的str 改变之后，它的上一层 str也跟着改变。这里有两种做法
        //1。参数使用 char **str 这样dfs中的 （*str）++之后 上一层的 str的指针会知道其发生改遍。 str本身不变 但是其指向的值变了
        //2。这里使用str 引用的方式  （char* &str） 为参数
        return Deserial(str);
        
    }
private:
    TreeNode* Deserial(char *&str) {
        if(*str=='#'){
            str++;
            return NULL;
        }
        int num=0;
        while(*str!='!'){
            num=num*10+(*str-'0');
            str++;
        }
        str++;
        TreeNode* root=new TreeNode(num);
        root->left=Deserial(str);
        root->right=Deserial(str);
        return root;
    }
};


