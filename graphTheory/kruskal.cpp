#include <iostream>
#include <algorithm>
using namespace std;
int m, n, fa[105], s;
struct node {
    int u, v, w;
}g[105];
bool cmp( node a, node b ){
    return a.w < b.w;
}
int find(int a){
    if(a==fa[a])return a;
    else{
        fa[a]=find(fa[a]);
        return fa[a];
    }
}
void merge(int a,int b){
    int a_f=find(a);
    int b_f=find(b);
    if(a_f!=b_f){
        fa[a_f]=b_f;
    }
}
int main(){

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for (int i = 0; i < m; i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    sort(g,g+m,cmp);
    int s=0, cnt=0;
    for(int i = 0; i< m; i++){
        if(cnt==n-1) break;
        if(find(g[i].u)!=find(g[i].v)){
            merge(g[i].u,g[i].v);
            s+=g[i].w;
            cnt++;
        }
    }
    cout<<s<<endl;
    return 0;
}
// 6 9
// 2 4 11
// 3 5 13 
// 4 6 3
// 5 6 4
// 2 3 6
// 4 5 7
// 1 2 1 
// 3 4 9
// 1 3 2
