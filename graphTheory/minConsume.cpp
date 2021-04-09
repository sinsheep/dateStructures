#include <bits/stdc++.h>
using namespace std;
int n, m;
double g[2005][2004];
int vis[2005] = {0};
int main(){
    cin >> n >> m;
    int x, y, z;
    memset(g,0,sizeof g);
    for(int i = 0; i < m; i++){
        cin>>x>>y>>z;
        g[x][y] = double(100-z)/100;
    }
    double dis[2005]={0};
    int a, b;
    cin >> a >> b;
    dis[a] = 0;
    memset(vis,false,sizeof(vis));
    vis[a] = true;
    queue<int> q;
    while(q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(g[u][i]!=0&&!vis[i]){
                dis[i] = max(dis[i],dis[i]*dis[u]);
                q.push(i);
                vis[i] = true;
            }
        }
    }
    printf("%.8lf",100.0/dis[b]);
    return 0;
}
