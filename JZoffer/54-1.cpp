#include <stdio.h>
#include <iostream>
using namespace  std;

class Solution
{
public: 
    Solution(): index(0) {
        for (int i = 0; i < 256; ++i) {
            store[i] = -1;
        }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        index++;
        if(store[ch]==-1){
            store[ch]=index;
        }else{
            store[ch]=-2;
        }
        
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int MinIndex=INT_MAX;
        char res='#';
        for(int i=0;i<256;i++){
            if(store[i]>=0 && MinIndex>store[i]){
                MinIndex=store[i];
                res=i;
            }
        }
        return res;
    }
 private:
     char store[256];   
     int index;
};