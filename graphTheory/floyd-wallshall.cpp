#include<iostream>
const int inf=1000005;
using namespace std;
int main(){
    int g[105][105],m,n,x,y,z;
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
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// 4 8
// 1 2 2
// 1 3 6
// 1 4 4
// 2 3 3 
// 3 1 7
// 3 4 1
// 4 1 5
// 4 3 12
