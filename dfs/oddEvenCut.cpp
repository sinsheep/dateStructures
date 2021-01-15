#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m, n, t, dx, dy, flag, tx, ty;
char mp[105][105];
int dir[][2]={0,1,1,0,-1,0,0,-1};
void dfs(int x,int y, int k){
    if(flag||k>t)return ;
    if(x<0||x>=m||y<0||y>=n||mp[x][y]=='X'){
        return ;
    }
    if(t==k&&mp[x][y]=='D'){
        flag=1;
        return ;
    }
    int dis=t-k-(abs(tx-x)+abs(ty-y));
    if(dis&1)return ;
    char c=mp[x][y];
    mp[x][y]='X';
    for(int i=0;i<4;i++){
        dfs(x+dir[i][0],y+dir[i][1],k+1);
    }
    mp[x][y]=c;
}
int main(){

    while(cin >> m >> n >> t,m&&n&&t){
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='S'){
                    dx=i;dy=j;
                }
                if(mp[i][j]=='D'){
                    tx=i;ty=j;
                }
                if(mp[i][j]=='X'){
                    cnt++;
                }
            }
        }
        flag=0;
        if(m*n-cnt-1>=t)dfs(dx,dy,0);
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
