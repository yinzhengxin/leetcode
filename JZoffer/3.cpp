#include <stdio.h>
#include <iostream>
#include <vector>
using namespace  std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
         vector<int> res;
        if(head==NULL)  return res;
        //反转链表  用来示例一下 简单方法用容器
        ListNode predummy=ListNode(0);
        ListNode *pre=&predummy;
        ListNode *cur=head;
        ListNode *next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        head->next=NULL;
        //求值
        while(pre!=NULL){
            res.push_back(pre->val);
            pre=pre->next;
        }
        return res;
    }
};
/*
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> result;
      stack<ListNode*> nodes;
      while(head!=nullptr){
            nodes.push(head);
            head=head->next;
      }
      while(!nodes.empty()){
            result.push_back(nodes.top()->val);
            nodes.pop();
      } 
      return result;
    }
};
*/

int main(){
    ListNode *head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(10000); 
    head->next->next->next=new ListNode(3);
    Solution sol;
    vector<int> res;
    res=sol.printListFromTailToHead(head);

    for(auto& num:res){
        cout<<num<<' ';
    }
    return 0;
}