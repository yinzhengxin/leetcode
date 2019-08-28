#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace  std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(charSet.find(ch)==charSet.end()){
            q.push(ch);
        }
        charSet[ch]++;
        
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && charSet[q.front()]>=2){
            q.pop();
        }
        if(q.empty()){
            return '#';
        }else{
            return q.front();
        }
    }
private:
    unordered_map<char,int> charSet;
    queue<char>    q;
};