#include<iostream>
const int inf=0x3f3f3f;
using namespace std;
int main(){
    int g[105][105],vis[105],dis[105],x,y,z,min,m,n,u;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        g[x][y]=z;
    }
    for(int i=1;i<=n;i++){
        dis[i]=g[1][i];
        vis[i]=0;
    }
    vis[1]=1;
    for(int k=1;k<=n-1;k++){
        min=inf;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&dis[i]<min){
                min=dis[i];
                u=i;
            }
        }
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(g[u][i]<inf&&dis[i]>dis[u]+g[u][i]){
                dis[i]=dis[u]+g[u][i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<endl;
    }
    return 0;
}
// 6 9
// 1 2 1
// 1 3 12 
// 2 3 9
// 2 4 3
// 3 5 5
// 4 3 4
// 4 5 13
// 4 6 15
// 5 6 4
