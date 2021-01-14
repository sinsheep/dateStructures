#include <iostream>
using namespace std;
int g[105][105],n,m,u[100],v[105],w[105],dis[105],bak[105];
const int inf = 10005;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        dis[i]=inf;
    }
    dis[1]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            bak[j]=dis[j];
        }
        for(int j=0;j<m;j++){
            if(dis[v[j]]>dis[u[j]]+w[j]){
                dis[v[j]]=dis[u[j]]+w[j];
            }
        }
        int check=0;
        for(int j=1;j<=n;j++){
            if(bak[j]!=dis[j]){
                check=1;
                break;
            }
        }
        if(!check)break;
    }
    for(int i=1;i<=n;i++){
        cout<<1<<"->"<<i<<":"<<dis[i]<<endl;
    }
}
// 5 7 
// 1 2 2
// 1 5 10
// 2 3 3
// 2 5 7
// 3 4 4
// 4 5 5
// 5 3 6
