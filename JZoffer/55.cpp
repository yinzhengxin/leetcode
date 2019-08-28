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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead)    return NULL;
        ListNode* slow=pHead;
        ListNode* fast=pHead;
        while(fast!= NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(pHead!=slow){
                    pHead=pHead->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};