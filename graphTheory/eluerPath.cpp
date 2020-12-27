#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int vis[1000],parent[1000],n,m;
void init(){
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}
int find(int n){
    return n==parent[n]?n:parent[n]=find(parent[n]);
}
void join(int x,int y){
    int x_p=find(x);
    int y_p=find(y);
    if(x_p!=y_p) parent[x_p]=y_p;
}
int main(){

    while(cin>>n>>m){
        init();
        memset(vis,0,sizeof(vis));
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            vis[u]++;
            vis[v]++;
            join(u,v);
        }
        int flag=1;
        for(int i=1;i<n;i++){
            printf("%d\n",parent[i]);
            if(parent[i]!=parent[i+1]||vis[i]%2){
                flag=0;
                break;
            }
        }
        if(flag)printf("Yes");
        else printf("No!");
    }
    return 0;
}
