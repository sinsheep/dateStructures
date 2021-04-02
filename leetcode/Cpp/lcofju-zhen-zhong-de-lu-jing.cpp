#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int x, int y, string s,vector<vector<char>>& board,bool *flag,string word){
        if(x<0||y<0||x>=board.size()||y>=board.size()||s.size()>word.size()||board[x][y]=='.'){
            return ;
        }
        if(s == word){
            return ;
        }
        char c = board[x][y];
        board[x][y] = '.';
        for(int i = 0; i < 4; i++){
            dfs(x+dir[i][0],y+dir[i][1],s+board[x][y],board,flag,word);
        }
        board[x][y] = c;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j<board[0].size();j++){
                if(word[0] == board[i][j]){
                    char c = word[i];
                    dfs(i,j,""+c,board,&flag,word);
                }
            }
        }
        return flag;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
