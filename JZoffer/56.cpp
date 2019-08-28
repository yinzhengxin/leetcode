#include <stdio.h>
#include <iostream>
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)    return NULL;
        ListNode dummyHead(0);
        ListNode* cur=&dummyHead;
        while(pHead!=NULL){
            int curVal=pHead->val;
            if(pHead->next == NULL || pHead->next->val != curVal){
                cur->next=pHead;
                cur=cur->next;
                pHead=pHead->next;
            }else{
                while(pHead != NULL && pHead->val==curVal){
                    pHead=pHead->next;
                }
            }
        }
        cur->next=NULL;
        return dummyHead.next;
    }
};