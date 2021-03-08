#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n, g[1005][1005], m, vis[1005], pos[1005], u, v;
void dfs(int x){
    if(vis[x]) return;
    vis[x] = 1;
    for (int i = 1; i <= n; i++){
        // cout<< g[x][i] << endl;
        if (g[x][i] == 1) {
            dfs(i);
        }
    }
}
int main(){
    while(cin >> n,n){
        cin >> m;
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        memset(pos, 0, sizeof pos);
        for (int i = 0; i < m; i++){
            cin >> u >> v;
            g[u][v] = 1;
            g[v][u] = 1;
            pos[u]++;
            pos[v]++;
       }
       dfs(1);
       int flag = 1;
       for (int i = 1; i <= n; i++) {
           // cout << vis[i] << pos[i] << endl;
           if (vis[i] == 0 ){
                flag = 0;
           }
           if(pos[i] % 2){
               flag = 0;
           }
       }
       cout << flag << endl;
    }
    return 0;
}


