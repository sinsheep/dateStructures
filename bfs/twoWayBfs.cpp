#include<iostream>
#include<queue>
#include<algorithm>
#define MAXN 1010
using namespace std;
int dir[][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,-1,1,1,-1};
int vis[2][MAXN][MAXN];
int m,n;
char map[MAXN][MAXN];
struct node{
    int x,y;
    bool check(){
        if(x<0||x>=m||y<0||y>=n||map[x][y]=='#')
            return false;
        return true;
    }
};
queue<node> q[2];
bool bfs(int x){
    int sz=q[x].size();
    while(sz--){
        node top=q[x].front();
        q[x].pop();
        for(int i=0;i<8-x*4;i++){
            node tmp=top;
            tmp.x+=dir[i][0];
            tmp.y+=dir[i][1];
            if(tmp.check()&&vis[x][tmp.x][tmp.y]==0){
                if(vis[x^1][tmp.x][tmp.y])return true;
                q[x].push(tmp);
                vis[x][tmp.x][tmp.y]=1;
            }
        }
    }
    return false;
}
int getMin(){
    int ans=0;
    while(!q[0].empty()||!q[0].empty()){
        ans++;
        if(bfs(0))return ans;
        if(bfs(1))return ans;
        if(bfs(1))return ans;
    }
    return -1;
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            getchar();
            cin>>map[i][j];
            if(map[i][j]=='C'){
                vis[0][i][j]=1;
                q[0].push({i,j});
            }
            if(map[i][j]=='D'){
                vis[1][i][j]=1;
                q[1].push({i,j});
            }
        }
    }
    int ans=getMin();
    if(ans!=-1){
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }else cout<<"NO"<<endl;

    return 0;
}
