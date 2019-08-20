#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 
//这里运用了 并归排序 但是这里是运用迭代的方法来做的。
//如用递归来做的话 slow=head fast=head->next
//则当fast fast->next一个为null时，slow为中间节点（奇数）中间节点左边（偶数）

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next=head;
        auto p=head;
        int len=0;
        while(p!=NULL){
            len++;
            p=p->next;
        }
     
        for(int i=1;i<len;i=i<<1){
            ListNode* tail=&dummyHead;
            ListNode* cur=dummyHead.next;
            
            while(cur){
                auto left=cur;
                auto right=cut(cur,i);
                cur=cut(right,i);
            
                tail->next =merge(left,right);
         
                while(tail->next) tail=tail->next;
                
            }    
        }
        return dummyHead.next;    
    }
    
    ListNode* cut(ListNode* cur,int size){
        while(cur!=NULL&&--size){
            cur=cur->next;
        }
        if(cur!=NULL){
            auto temp=cur->next;
            cur->next=NULL;
            return temp;
        }else{
            return NULL;
        }  
    }
    
    ListNode* merge(ListNode* l,ListNode* r){
        ListNode dummyHead(0);
        auto p=&dummyHead;
        while(l&&r){
            if(l->val<=r->val){
                p->next=l;
                p=l;
                l=l->next;
            }else{
                p->next=r;
                p=r;
                r=r->next;
            }
        }
        p->next=l?l:r;
        return dummyHead.next;   
    } 
};