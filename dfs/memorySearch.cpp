#include<bits/stdc++.h>
#define rep(i,qs,n) for(int i=qs;i<=n;i++)
using namespace std;
int n,m,t,dx,dy,flag;
int mp[105][105];
int vis[105][105];
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int x,int y){
    int s=1;
    if(vis[x][y]!=0)
    {
        return vis[x][y];
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx>=0&&dy>=0&&dx<m&&dy<n)
        {
            if(mp[dx][dy]<mp[x][y])
            {
                int q=1;
                q+=dfs(dx,dy);
                s=max(s,q);
            }
        }
         
    }
    vis[x][y]=s;
    return s;
}
int main(){
    while(cin>>m>>n)
    {
        int maxl=0;
        memset(vis,0,sizeof(vis));
        rep(i,0,m-1)
            rep(j,0,n-1)
                scanf("%d",&mp[i][j]);
        rep(i,0,m-1)
            rep(j,0,n-1)
            {
                dfs(i,j);
                maxl=max(maxl,vis[i][j]);
            }
                 
//      rep(i,0,m-1)
//      {
//          rep(j,0,n-1)
//              cout<<vis[i][j]<<" ";
//          cout<<endl;
//      }   
        cout<<maxl<<endl;
    }
}
