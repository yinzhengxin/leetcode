#include<iostream>
#include<deque>
#include<stdio.h>

using namespace std;

struct TicketP5661{
    int tpy;
    int money;
    int ts;
    bool  used;
};

int main(){
    deque<TicketP5661> tickts;
    int cost = 0;
    int row;
    scanf("%d",&row);
    for(int i=0;i<row;++i){
        int tpy,money,ts;
        cin>>tpy>>money>>ts;
        if (tpy == 0){
            tickts.push_back(TicketP5661{tpy:tpy,money:money,ts:ts});
            cost+=money;
        }else if (tpy==1){
            while(tickts.size()!=0 && tickts.front().ts +45 <ts){
                tickts.pop_front();
            }
            int flag=false;
            for(auto it=tickts.begin();it!=tickts.end();++it){
                if (!(*it).used && ((*it).money >= money)){
                    flag=true;
                    (*it).used=true;
                    break;
                }
            }
            if (!flag){
                cost+=money;
            }
        }
    }
    cout<<cost;
}

