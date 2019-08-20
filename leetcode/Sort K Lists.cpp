#include <stdio.h> //ptr NULL define
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//分而治之  空间复杂度O(1) 时间复杂度O(logk*N)
using namespace std;
#include <vector>
#include <iostream>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        int len=lists.size();
         
        for(int i=1;i<len;i=2*i){
            for(int j=0; j<len-i; j=j+2*i){
                lists[j]=merge2Lists(lists[j],lists[j+i]);
            }
        }
        return lists[0];
    }
     ListNode* merge2Lists(ListNode* l1,ListNode* l2){
         ListNode dummyhead(0);
         ListNode* p=&dummyhead;
         while(l1!=NULL&&l2!=NULL){
             if(l1->val<=l2->val){
                 p->next=l1;
                 l1=l1->next;
                 p=p->next;
             }else{
                 p->next=l2;
                 l2=l2->next;
                 p=p->next;
             }
         }
        if(l1==NULL){
            p->next=l2;
        }else{
            p->next=l1;
        }
        return dummyhead.next;
     }
};