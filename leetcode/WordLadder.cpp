#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //单项 Bfs 加快速度也可以用双向bfs 来处理
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //1.这里使用的构造方法。值得注意。
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> visit;
        queue<string> q;
        q.push(beginWord);
        visit.insert(beginWord);
        int res=1;
        while(!q.empty()) {
            int qSize=q.size();
            while(qSize--){
                auto t=q.front();
                q.pop();
                //2.这里可以用正则来替代
                for(int i=0;i<t.size();i++){
                    for(char ch='a';ch<='z';ch++){
                        string temp=t;
                        temp[i]=ch;
                        if(dict.count(temp) && !visit.count(temp)){
                            if(temp==endWord)  { return res+1;}
                            q.push(temp);
                            visit.insert(temp);
                        }
                    }
                }
            }
            res++;
        }
    return 0;
    }
};