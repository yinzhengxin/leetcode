#include <vector>
#include <string>
//跟剑指offer上的最后题类似 dfs 深度搜索
using namespace  std;
//dfs 同一单元格内不允许重复使用。
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        vector<vector<bool> > visit(board.size(),vector<bool>(board[0].size()));
        for(int i = 0; i < board.size();++i){
            for(int j = 0; j < board[i].size();++j){
                if(board[i][j] == word[0]){
                    visit[i][j]=1;
                    bool res=dfs(board,i,j,word.substr(1),visit);
                    visit[i][j]=0;
                    if(res) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char> >& board, int x,int y, string word, vector<vector<bool> >& visit){
        if(word.empty()){return true;}
        bool res=false;
        if(x-1>=0 && visit[x-1][y]==0 && board[x-1][y]==word[0]){
            visit[x-1][y]=1;
            res=res|| dfs(board,x-1,y,word.substr(1),visit);
            visit[x-1][y]=0;
            if(res) return true;
        }
        if(x+1<board.size() && visit[x+1][y]==0 && board[x+1][y]==word[0]){
            visit[x+1][y]=1;
            res=res||dfs(board,x+1,y,word.substr(1),visit);
            visit[x+1][y]=0;
            if(res) return true;
        }
        if(y-1>=0 && visit[x][y-1]==0 && board[x][y-1]==word[0]){
            visit[x][y-1]=1;
            res=res||dfs(board,x,y-1,word.substr(1),visit);
            visit[x][y-1]=0;
            if(res) return true;
        }
        if(y+1<board[x].size() && visit[x][y+1]==0 && board[x][y+1]==word[0]){
            visit[x][y+1]=1;
            res=res||dfs(board,x,y+1,word.substr(1),visit);
            visit[x][y+1]=0;
            if(res) return true;
        }
        return false;
    }
};