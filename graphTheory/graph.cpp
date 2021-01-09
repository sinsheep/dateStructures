#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int x,y;
};
vector<int>g[10];
bool vis[10],vis1[10];
int dis[10];
void dfs(int now){
    vis[now]=1;
    for(auto to:g[now]){
        if(!vis[to]){
            dfs(to);
        }
    }
    return ;
}
queue<int> q;
void bfs(int now){
    q.push(now);
    memset(dis,0x3f,sizeof(dis));
    dis[now]=0;
    vis1[now]=1;
    while(!q.empty()){
        int from=q.front();
        q.pop();
        for(auto to:g[from]){
            if(!vis1[to]){
                dis[to]=min(dis[to],dis[from]+1);
                q.push(to);
                vis1[to]=1;
            }
        }
    }
    for(int i=1;i<=7;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(2);
    for(int i=1;i<=n;i++){
        printf("%d %c",vis[i],(i==n)?'\n':' ');
    }
    bfs(2);
    return 0;
}
