#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int directed,g[105][105],n,m;
void addEdge(int v,int w){
    if(v<0||v>=n||w<0||w>=n){
        return ;
    }
    if(g[v][w])return ;
    g[v][w]=1;
    if(!directed){
        g[w][v]=1;
    }
    m++;
}
vector<int> adj(int v){
    vector<int> adj;
    for(int i=0;i<n;i++){
        if(g[v][i])
            adj.push_back(i);
    }
    return adj;
}
int main(){

    int k,x,y;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        addEdge(x,y);
    }
    return 0;
}

